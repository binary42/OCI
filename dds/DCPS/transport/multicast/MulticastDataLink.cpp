/*
 * $Id: MulticastDataLink.cpp 6893 2015-01-29 15:27:49Z wilsonj $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "MulticastDataLink.h"
#include "MulticastSession.h"
#include "MulticastSessionFactory.h"
#include "MulticastTransport.h"

#include "ace/Default_Constants.h"
#include "ace/Global_Macros.h"
#include "ace/Log_Msg.h"
#include "ace/Truncate.h"
#include "ace/OS_NS_sys_socket.h"

#include "tao/ORB_Core.h"

#include "dds/DCPS/Service_Participant.h"

#ifndef __ACE_INLINE__
# include "MulticastDataLink.inl"
#endif  /* __ACE_INLINE__ */

namespace OpenDDS {
namespace DCPS {

MulticastDataLink::MulticastDataLink(MulticastTransport* transport,
    MulticastSessionFactory* session_factory,
    MulticastPeer local_peer,
    bool is_active)
: DataLink(transport, 0 /*priority*/, false /*loopback*/, is_active),
  transport_(transport),
  session_factory_(session_factory, false),
  local_peer_(local_peer),
  config_(0),
  reactor_task_(0),
  send_buffer_(0)
{
}

MulticastDataLink::~MulticastDataLink()
{
  if (this->send_buffer_) {
    this->send_strategy_->send_buffer(0);
    delete this->send_buffer_;
  }
}

void
MulticastDataLink::configure(MulticastInst* config,
    TransportReactorTask* reactor_task)
{
  this->config_ = config;
  this->reactor_task_ = reactor_task;
}

void
MulticastDataLink::send_strategy(MulticastSendStrategy* send_strategy)
{
  // A send buffer may be bound to the send strategy to ensure a
  // configured number of most-recent datagrams are retained:
  if (this->session_factory_->requires_send_buffer()) {
    ACE_NEW_NORETURN(this->send_buffer_,
        SingleSendBuffer(this->config_->nak_depth_,
            this->config_->max_samples_per_packet_));
    if (!this->send_buffer_) {
      ACE_ERROR((LM_ERROR,
          ACE_TEXT("(%P|%t) ERROR: ")
          ACE_TEXT("MulticastDataLink::send_strategy: ")
          ACE_TEXT("failed to create SingleSendBuffer!\n")));
      return;
    }
    send_strategy->send_buffer(this->send_buffer_);
  }
  this->send_strategy_ = send_strategy;
}

void
MulticastDataLink::receive_strategy(MulticastReceiveStrategy* recv_strategy)
{
  this->recv_strategy_ = recv_strategy;
}

bool
MulticastDataLink::join(const ACE_INET_Addr& group_address)
{
  const std::string& net_if = this->config_->local_address_;
  if (this->socket_.join(group_address, 1,
      net_if.empty() ? 0 :
          ACE_TEXT_CHAR_TO_TCHAR(net_if.c_str())) != 0) {
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: MulticastDataLink::join: ")
        ACE_TEXT("ACE_SOCK_Dgram_Mcast::join failed %m.\n")),
        false);
  }
  VDBG_LVL((LM_DEBUG, ACE_TEXT("(%P|%t) MulticastDataLink::join OK\n")), 6);

  ACE_HANDLE handle = this->socket_.get_handle();
  char ttl = this->config_->ttl_;

  if (ACE_OS::setsockopt(handle,
      IPPROTO_IP,
      IP_MULTICAST_TTL,
      &ttl,
      sizeof(ttl)) < 0) {
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: ")
        ACE_TEXT("MulticastDataLink::join: ")
        ACE_TEXT("ACE_OS::setsockopt TTL failed.\n")),
        false);
  }

  int rcv_buffer_size = ACE_Utils::truncate_cast<int>(this->config_->rcv_buffer_size_);
  if (rcv_buffer_size != 0
      && ACE_OS::setsockopt(handle, SOL_SOCKET,
          SO_RCVBUF,
          (char *) &rcv_buffer_size,
          sizeof (int)) < 0) {
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: ")
        ACE_TEXT("MulticastDataLink::join: ")
        ACE_TEXT("ACE_OS::setsockopt RCVBUF failed.\n")),
        false);
  }

#if defined (ACE_DEFAULT_MAX_SOCKET_BUFSIZ)
  int snd_size = ACE_DEFAULT_MAX_SOCKET_BUFSIZ;

  if (ACE_OS::setsockopt(handle, SOL_SOCKET,
      SO_SNDBUF,
      (char *) &snd_size,
      sizeof(snd_size)) < 0
      && errno != ENOTSUP) {
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: ")
        ACE_TEXT("MulticastDataLink::join: ")
        ACE_TEXT("ACE_OS::setsockopt SNDBUF failed to set the send buffer size to %d errno %m\n"),
        snd_size),
        false);
  }
#endif /* ACE_DEFAULT_MAX_SOCKET_BUFSIZ */

  if (start(static_rchandle_cast<TransportSendStrategy>(this->send_strategy_),
      static_rchandle_cast<TransportStrategy>(this->recv_strategy_))
      != 0) {
    this->socket_.close();
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: ")
        ACE_TEXT("MulticastDataLink::join: ")
        ACE_TEXT("DataLink::start failed!\n")),
        false);
  }

  return true;
}

MulticastSession*
MulticastDataLink::find_session(MulticastPeer remote_peer)
{
  ACE_GUARD_RETURN(ACE_SYNCH_RECURSIVE_MUTEX,
      guard,
      this->session_lock_,
      0);

  MulticastSessionMap::iterator it(this->sessions_.find(remote_peer));
  if (it != this->sessions_.end()) {
    MulticastSession_rch sess = it->second;
    return sess._retn();
  }
  else return 0;
}

MulticastSession*
MulticastDataLink::find_or_create_session(MulticastPeer remote_peer)
{
  ACE_GUARD_RETURN(ACE_SYNCH_RECURSIVE_MUTEX,
      guard,
      this->session_lock_,
      0);

  MulticastSessionMap::iterator it(this->sessions_.find(remote_peer));
  if (it != this->sessions_.end()) {
    MulticastSession_rch sess = it->second;
    return sess._retn();
  }

  MulticastSession_rch session =
    this->session_factory_->create(transport()->reactor(), transport()->reactor_owner(), this, remote_peer);
  if (session.is_nil()) {
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: ")
        ACE_TEXT("MulticastDataLink::find_or_create_session: ")
        ACE_TEXT("failed to create session for remote peer: 0x%x!\n"),
        remote_peer),
        0);
  }

  std::pair<MulticastSessionMap::iterator, bool> pair = this->sessions_.insert(
      MulticastSessionMap::value_type(remote_peer, session));
  if (pair.first == this->sessions_.end()) {
    ACE_ERROR_RETURN((LM_ERROR,
        ACE_TEXT("(%P|%t) ERROR: ")
        ACE_TEXT("MulticastDataLink::find_or_create_session: ")
        ACE_TEXT("failed to insert session for remote peer: 0x%x!\n"),
        remote_peer),
        0);
  }
  return session._retn();
}

bool
MulticastDataLink::check_header(const TransportHeader& header)
{
  ACE_GUARD_RETURN(ACE_SYNCH_RECURSIVE_MUTEX,
      guard,
      this->session_lock_,
      false);

  MulticastSessionMap::iterator it(this->sessions_.find(header.source_));
  if (it == this->sessions_.end() && is_active()) {
    return false;
  }
  if (it != this->sessions_.end() && it->second->acked()) {
    return it->second->check_header(header);
  }

  return true;
}

bool
MulticastDataLink::check_header(const DataSampleHeader& header)
{
  if (header.message_id_ == TRANSPORT_CONTROL) return true;

  ACE_GUARD_RETURN(ACE_SYNCH_RECURSIVE_MUTEX,
      guard,
      this->session_lock_,
      false);

  // Skip data sample unless there is a session for it.
  return (this->sessions_.count(receive_strategy()->received_header().source_) > 0);
}

bool
MulticastDataLink::reassemble(ReceivedDataSample& data,
    const TransportHeader& header)
{
  ACE_GUARD_RETURN(ACE_SYNCH_RECURSIVE_MUTEX,
      guard,
      this->session_lock_,
      false);

  MulticastSessionMap::iterator it(this->sessions_.find(header.source_));
  if (it == this->sessions_.end()) return false;
  if (it->second->acked()) {
    return it->second->reassemble(data, header);
  }
  return false;
}

void
MulticastDataLink::sample_received(ReceivedDataSample& sample)
{
  switch (sample.header_.message_id_) {
  case TRANSPORT_CONTROL: {
    // Transport control samples are delivered to all sessions
    // regardless of association status:
    {
      char* const ptr = sample.sample_ ? sample.sample_->rd_ptr() : 0;

      ACE_GUARD(ACE_SYNCH_RECURSIVE_MUTEX,
          guard,
          this->session_lock_);

      const TransportHeader& theader = receive_strategy()->received_header();

      if (!is_active() && sample.header_.submessage_id_ == MULTICAST_SYN &&
          sessions_.find(theader.source_) == sessions_.end()) {
        // We have received a SYN but there is no session (yet) for this source.
        // Depending on the data, we may need to send SYNACK.

        guard.release();
        syn_received_no_session(theader.source_, sample.sample_,
            theader.swap_bytes());
        if (ptr) {
          sample.sample_->rd_ptr(ptr);
        }
        return;
      }

      MulticastSessionMap temp_sessions(sessions_);
      guard.release();

      for (MulticastSessionMap::iterator it(temp_sessions.begin());
          it != temp_sessions.end(); ++it) {
        it->second->control_received(sample.header_.submessage_id_,
            sample.sample_);
        // reset read pointer
        if (ptr) {
          sample.sample_->rd_ptr(ptr);
        }
      }
    }
  } break;

  case SAMPLE_ACK:
    ack_received(sample);
    break;

  default:
    if (!duplicate_data_sample(sample.header_)) {
      data_received(sample);
    }
    break;
  }
}

bool
MulticastDataLink::duplicate_data_sample(const DataSampleHeader& header)
{
  if (header.sequence_ == SequenceNumber::SEQUENCENUMBER_UNKNOWN()
      || header.publication_id_ == GUID_UNKNOWN) {
    return false;
  }
  ACE_GUARD_RETURN(ACE_SYNCH_RECURSIVE_MUTEX, guard, session_lock_, false);
  return !data_samples_seen_[header.publication_id_].insert(header.sequence_);
}

void
MulticastDataLink::release_remote_i(const RepoId& remote)
{
  ACE_GUARD(ACE_SYNCH_RECURSIVE_MUTEX, guard, session_lock_);
  data_samples_seen_.erase(remote);
}

void
MulticastDataLink::syn_received_no_session(MulticastPeer source,
    ACE_Message_Block* data,
    bool swap_bytes)
{
  Serializer serializer_read(data, swap_bytes);

  MulticastPeer local_peer;
  serializer_read >> local_peer;

  if (local_peer != local_peer_) {
    return;
  }

  VDBG_LVL((LM_DEBUG, "(%P|%t) MulticastDataLink[%C]::syn_received_no_session "
      "send_synack local 0x%x remote 0x%x\n",
      config_->name().c_str(), local_peer, source), 2);

  ACE_Message_Block* synack_data = new ACE_Message_Block(sizeof(MulticastPeer));

  Serializer serializer_write(synack_data);
  serializer_write << source;

  DataSampleHeader header;
  ACE_Message_Block* control =
      create_control(MULTICAST_SYNACK, header, synack_data);

  const int error = send_control(header, control);
  if (error != SEND_CONTROL_OK) {
    ACE_ERROR((LM_ERROR, "(%P|%t) MulticastDataLink::syn_received_no_session: "
        "ERROR: send_control failed: %d!\n", error));
    return;
  }

  transport_->passive_connection(local_peer, source);
}

void
MulticastDataLink::stop_i()
{
  ACE_GUARD(ACE_SYNCH_RECURSIVE_MUTEX,
      guard,
      this->session_lock_);

  for (MulticastSessionMap::iterator it(this->sessions_.begin());
      it != this->sessions_.end(); ++it) {
    it->second->stop();
  }
  this->sessions_.clear();

  this->socket_.close();
}

} // namespace DCPS
} // namespace OpenDDS
