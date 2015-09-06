/*
 * $Id: ShmemLoader.h 5541 2012-05-08 20:04:18Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_SHMEMLOADER_H
#define OPENDDS_SHMEMLOADER_H

#include "Shmem_Export.h"

#include "ace/Global_Macros.h"
#include "ace/Service_Config.h"
#include "ace/Service_Object.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Shmem_Export ShmemLoader
  : public ACE_Service_Object {
public:
  virtual int init(int argc, ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE_EXPORT(OpenDDS_Shmem, ShmemLoader)
ACE_FACTORY_DECLARE(OpenDDS_Shmem, ShmemLoader)

} // namespace DCPS
} // namespace OpenDDS

#endif  /* OPENDDS_SHMEMLOADER_H */
