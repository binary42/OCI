/*
 * $Id: Udp.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_UDP_H
#define DCPS_UDP_H

#include "Udp_Export.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Udp_Export UdpInitializer {
public:
  UdpInitializer();
};

static UdpInitializer udp_init;

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_UDP_H */
