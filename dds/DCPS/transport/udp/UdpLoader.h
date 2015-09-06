/*
 * $Id: UdpLoader.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_UDPLOADER_H
#define DCPS_UDPLOADER_H

#include "Udp_Export.h"

#include "ace/Global_Macros.h"
#include "ace/Service_Config.h"
#include "ace/Service_Object.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Udp_Export UdpLoader
  : public ACE_Service_Object {
public:
  virtual int init(int argc, ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE_EXPORT(OpenDDS_Udp, UdpLoader)
ACE_FACTORY_DECLARE(OpenDDS_Udp, UdpLoader)

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_UDPLOADER_H */
