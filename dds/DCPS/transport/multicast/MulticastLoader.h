/*
 * $Id: MulticastLoader.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_MULTICASTLOADER_H
#define DCPS_MULTICASTLOADER_H

#include "Multicast_Export.h"

#include "ace/Global_Macros.h"
#include "ace/Service_Config.h"
#include "ace/Service_Object.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Multicast_Export MulticastLoader
  : public ACE_Service_Object {
public:
  virtual int init(int argc, ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE_EXPORT(OpenDDS_Multicast, MulticastLoader)
ACE_FACTORY_DECLARE(OpenDDS_Multicast, MulticastLoader)

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_MULTICASTLOADER_H */
