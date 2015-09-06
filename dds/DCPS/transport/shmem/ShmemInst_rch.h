/*
 * $Id: ShmemInst_rch.h 5541 2012-05-08 20:04:18Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_SHMEMINST_RCH_H
#define OPENDDS_SHMEMINST_RCH_H

#include "dds/DCPS/RcHandle_T.h"

namespace OpenDDS {
namespace DCPS {

class ShmemInst;

typedef RcHandle<ShmemInst> ShmemInst_rch;

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_SHMEMINST_RCH_H */
