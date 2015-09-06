/*
 * $Id: UdpSendStrategy.h 4516 2011-05-18 21:40:23Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_UDPSENDSTRATEGY_H
#define DCPS_UDPSENDSTRATEGY_H

#include "Udp_Export.h"

#include "dds/DCPS/transport/framework/TransportSendStrategy.h"

namespace OpenDDS {
namespace DCPS {

class UdpDataLink;

class OpenDDS_Udp_Export UdpSendStrategy
  : public TransportSendStrategy {
public:
  explicit UdpSendStrategy(UdpDataLink* link);

  virtual void stop_i();

protected:
  virtual ssize_t send_bytes_i(const iovec iov[], int n);

  virtual size_t max_message_size() const
  {
    return UDP_MAX_MESSAGE_SIZE;
  }

private:
  UdpDataLink* link_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif /* DCPS_UDPSENDSTRATEGY_H */
