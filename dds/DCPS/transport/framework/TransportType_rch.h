/*
 * $Id: TransportType_rch.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_TRANSPORTTYPE_RCH_H
#define OPENDDS_DCPS_TRANSPORTTYPE_RCH_H

#include <ace/config.h>
#ifndef ACE_LACKS_PRAGMA_ONCE
#pragma once
#endif

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class TransportType;
typedef RcHandle<TransportType> TransportType_rch;

}
}

#endif /* OPENDDS_DCPS_TRANSPORTTYPE_RCH_H */
