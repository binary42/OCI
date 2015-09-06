/*
 * $Id: Tcp.h 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_TCP_H
#define OPENDDS_TCP_H

#include /**/ "ace/pre.h"

#include "Tcp_export.h"
#include "ace/Service_Object.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Tcp_Export Tcp_Initializer {
public:
  // Constructor.
  Tcp_Initializer();
};

static Tcp_Initializer tcp_initializer;

}
}

#include /**/ "ace/post.h"

#endif /* OPENDDS_TCP_H */
