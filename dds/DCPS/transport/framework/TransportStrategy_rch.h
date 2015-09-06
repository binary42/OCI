/*
 * $Id: TransportStrategy_rch.h 5266 2012-01-21 04:36:48Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_TRANSPORTSTRATEGY_RCH_H
#define OPENDDS_DCPS_TRANSPORTSTRATEGY_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class TransportStrategy;

typedef RcHandle<TransportStrategy> TransportStrategy_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_DCPS_TRANSPORTSTRATEGY_RCH_H */