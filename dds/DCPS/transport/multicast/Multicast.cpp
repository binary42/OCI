/*
 * $Id: Multicast.cpp 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "Multicast.h"
#include "MulticastLoader.h"

#include "ace/Service_Config.h"

namespace OpenDDS {
namespace DCPS {

MulticastInitializer::MulticastInitializer()
{
  ACE_Service_Config::process_directive(ace_svc_desc_MulticastLoader);

#if (OPENDDS_MULTICAST_HAS_DLL == 0)
  ACE_Service_Config::process_directive(ACE_TEXT("static OpenDDS_Multicast"));
#endif  /* OPENDDS_MULTICAST_HAS_DLL */
}

} // namespace DCPS
} // namespace OpenDDS
