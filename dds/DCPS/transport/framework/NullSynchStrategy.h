/*
 * $Id: NullSynchStrategy.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_NULLSYNCHSTRATEGY_H
#define OPENDDS_DCPS_NULLSYNCHSTRATEGY_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynchStrategy.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Dcps_Export NullSynchStrategy : public ThreadSynchStrategy {
public:

  NullSynchStrategy();
  virtual ~NullSynchStrategy();

  virtual ThreadSynch* create_synch_object(
    ThreadSynchResource* synch_resource,
    long                 priority,
    int                  scheduler);
};

} // namespace DCPS
} // namespace OpenDDS

#endif  /* OPENDDS_DCPS_NULLSYNCHSTRATEGY_H */
