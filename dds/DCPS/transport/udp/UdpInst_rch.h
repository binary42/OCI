/*
 * $Id: UdpInst_rch.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_UDPINST_RCH_H
#define OPENDDS_UDPINST_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class UdpInst;

typedef RcHandle<UdpInst> UdpInst_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_UDPINST_RCH_H */
