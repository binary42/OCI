/*
 * $Id: UdpSendStrategy.cpp 6025 2013-12-20 00:28:15Z martinezm $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "UdpSendStrategy.h"
#include "UdpDataLink.h"
#include "UdpInst.h"
#include "dds/DCPS/transport/framework/NullSynchStrategy.h"

namespace OpenDDS {
namespace DCPS {

UdpSendStrategy::UdpSendStrategy(UdpDataLink* link)
  : TransportSendStrategy(0, TransportInst_rch(link->config(), false),
                          0,  // synch_resource
                          link->transport_priority(),
                          new NullSynchStrategy),
    link_(link)
{
}

ssize_t
UdpSendStrategy::send_bytes_i(const iovec iov[], int n)
{
  ACE_SOCK_Dgram& socket = this->link_->socket();
  return socket.send(iov, n, this->link_->remote_address());
}

void
UdpSendStrategy::stop_i()
{
}

} // namespace DCPS
} // namespace OpenDDS
