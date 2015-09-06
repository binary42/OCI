/*
 * $Id: ReceiveListenerSet.cpp 5266 2012-01-21 04:36:48Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/

#include "dds/DCPS/GuidConverter.h"

#include "ReceiveListenerSet.h"

#if !defined (__ACE_INLINE__)
#include "ReceiveListenerSet.inl"
#endif /* __ACE_INLINE__ */

OpenDDS::DCPS::ReceiveListenerSet::~ReceiveListenerSet()
{
  DBG_ENTRY_LVL("ReceiveListenerSet","~ReceiveListenerSet",6);
}

bool
OpenDDS::DCPS::ReceiveListenerSet::exist(const RepoId& local_id,
                                         bool& last)
{
  GuardType guard(this->lock_);

  last = true;

  TransportReceiveListener* listener = 0;

  if (find(map_, local_id, listener) == -1) {
    OpenDDS::DCPS::GuidConverter converter(local_id);
    ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ReceiveListenerSet::exist: ")
               ACE_TEXT("could not find local %C.\n"),
               std::string(converter).c_str()));

    return false;
  }

  if (listener == 0) {
    OpenDDS::DCPS::GuidConverter converter(local_id);
    ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ReceiveListenerSet::exist: ")
               ACE_TEXT("listener for local %C is nil.\n"),
               std::string(converter).c_str()));

    return false;
  }

  last = map_.size() == 1;
  return true;
}

void
OpenDDS::DCPS::ReceiveListenerSet::get_keys(ReaderIdSeq & ids)
{
  GuardType guard(this->lock_);

  for (MapType::iterator iter = map_.begin();
       iter != map_.end(); ++ iter) {
    push_back(ids, iter->first);
  }
}

bool
OpenDDS::DCPS::ReceiveListenerSet::exist(const RepoId& local_id)
{
  GuardType guard(this->lock_);

  TransportReceiveListener* listener = 0;
  return (find(map_, local_id, listener) == -1 ? false : true);
}

void
OpenDDS::DCPS::ReceiveListenerSet::clear()
{
  GuardType guard(this->lock_);
  this->map_.clear();
}
