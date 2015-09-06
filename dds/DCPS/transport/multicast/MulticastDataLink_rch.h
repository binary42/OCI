/*
 * $Id: MulticastDataLink_rch.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_MULTICASTDATALINK_RCH_H
#define DCPS_MULTICASTDATALINK_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class MulticastDataLink;

typedef RcHandle<MulticastDataLink> MulticastDataLink_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_MULTICASTDATALINK_RCH_H */
