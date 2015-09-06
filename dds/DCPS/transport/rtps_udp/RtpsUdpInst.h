/*
 * $Id: RtpsUdpInst.h 5982 2013-06-14 23:00:46Z martinezm $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_RTPSUDPINST_H
#define DCPS_RTPSUDPINST_H

#include "Rtps_Udp_Export.h"

#include "dds/DCPS/transport/framework/TransportInst.h"

namespace OpenDDS {
namespace RTPS {
  class Sedp;
}

namespace DCPS {
class RtpsUdpTransport;
class TransportReceiveListener;

class OpenDDS_Rtps_Udp_Export RtpsUdpInst : public TransportInst {
public:

  ACE_INET_Addr local_address_;

  bool use_multicast_;
  short ttl_;
  ACE_INET_Addr multicast_group_address_;
  std::string multicast_interface_;

  size_t nak_depth_;
  ACE_Time_Value nak_response_delay_, heartbeat_period_,
    heartbeat_response_delay_, handshake_timeout_, durable_data_timeout_;

  virtual int load(ACE_Configuration_Heap& cf,
                   ACE_Configuration_Section_Key& sect);

  /// Diagnostic aid.
  virtual void dump(std::ostream& os);

  bool is_reliable() const { return true; }
  bool requires_cdr() const { return true; }

private:
  friend class RtpsUdpType;
  explicit RtpsUdpInst(const std::string& name);

  TransportImpl* new_impl(const TransportInst_rch& inst);

  friend class RTPS::Sedp;
  friend class RtpsUdpTransport;
  TransportReceiveListener* opendds_discovery_default_listener_;
  RepoId opendds_discovery_guid_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_RTPSUDPINST_H */
