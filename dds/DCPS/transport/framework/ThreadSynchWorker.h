/*
 * $Id: ThreadSynchWorker.h 6028 2014-01-08 03:09:32Z martinezm $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_THREADSYNCHWORKER_H
#define OPENDDS_DCPS_THREADSYNCHWORKER_H

#include "dds/DCPS/dcps_export.h"

#include "ace/Event_Handler.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Dcps_Export ThreadSynchWorker {
public:

  virtual ~ThreadSynchWorker();

  enum WorkOutcome {
    WORK_OUTCOME_MORE_TO_DO,
    WORK_OUTCOME_NO_MORE_TO_DO,
    WORK_OUTCOME_CLOGGED_RESOURCE,
    WORK_OUTCOME_BROKEN_RESOURCE
  };

  virtual WorkOutcome perform_work() = 0;

  /// Indicate that queued data is available to be sent.
  virtual void schedule_output();

  /// DataLink reference value for diagnostics.
  std::size_t id() const;

protected:

  ThreadSynchWorker( std::size_t id = 0);

private:
  std::size_t id_;
};

} // namespace DCPS
} // namespace OpenDDS

#if defined (__ACE_INLINE__)
#include "ThreadSynchWorker.inl"
#endif /* __ACE_INLINE__ */

#endif  /* OPENDDS_DCPS_THREADSYNCHWORKER_H */
