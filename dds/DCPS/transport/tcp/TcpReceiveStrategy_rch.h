/*
 * $Id: TcpReceiveStrategy_rch.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 * Copyright 2009 Object Computing, Inc.
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_TCPRECEIVESTRATEGY_RCH_H
#define OPENDDS_TCPRECEIVESTRATEGY_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class TcpReceiveStrategy;

typedef RcHandle<TcpReceiveStrategy> TcpReceiveStrategy_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_TCPRECEIVESTRATEGY_RCH_H */
