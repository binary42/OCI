/*
 * $Id: NullSynch.inl 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "EntryExit.h"

ACE_INLINE
OpenDDS::DCPS::NullSynch::NullSynch(ThreadSynchResource* resource)
  : ThreadSynch(0)
{
  DBG_ENTRY_LVL("NullSynch","NullSynch",6);
  ACE_UNUSED_ARG(resource);
}
