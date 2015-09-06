/*
 * $Id: MulticastSendStrategy_rch.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_MULTICASTSENDSTRATEGY_RCH_H
#define DCPS_MULTICASTSENDSTRATEGY_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class MulticastSendStrategy;

typedef RcHandle<MulticastSendStrategy> MulticastSendStrategy_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_MULTICASTSENDSTRATEGY_RCH_H */
