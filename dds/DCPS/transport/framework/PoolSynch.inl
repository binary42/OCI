/*
 * $Id: PoolSynch.inl 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "EntryExit.h"

ACE_INLINE
OpenDDS::DCPS::PoolSynch::PoolSynch(PoolSynchStrategy* strategy,
                                    ThreadSynchResource* synch_resource)
  : ThreadSynch(synch_resource),
    strategy_(strategy)
{
  DBG_ENTRY_LVL("PoolSynch","PoolSynch",6);
  // TBD
}
