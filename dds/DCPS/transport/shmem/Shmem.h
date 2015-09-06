/*
 * $Id: Shmem.h 5541 2012-05-08 20:04:18Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_SHMEM_H
#define OPENDDS_SHMEM_H

#include "Shmem_Export.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Shmem_Export ShmemInitializer {
public:
  ShmemInitializer();
};

static ShmemInitializer shmem_init;

} // namespace DCPS
} // namespace OpenDDS

#endif  /* OPENDDS_SHMEM_H */
