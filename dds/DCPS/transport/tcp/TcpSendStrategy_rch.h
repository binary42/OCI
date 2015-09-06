/*
 * $Id: TcpSendStrategy_rch.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_TCPSENDSTRATEGY_RCH_H
#define OPENDDS_TCPSENDSTRATEGY_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class TcpSendStrategy;

typedef RcHandle<TcpSendStrategy> TcpSendStrategy_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_TCPSENDSTRATEGY_RCH_H */
