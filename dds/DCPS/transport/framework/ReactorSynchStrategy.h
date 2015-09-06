/*
 * $Id: ReactorSynchStrategy.h 6762 2015-01-08 23:08:12Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_REACTORSYNCHSTRATEGY_H
#define OPENDDS_DCPS_REACTORSYNCHSTRATEGY_H

#include "dds/DCPS/dcps_export.h"
#include "ThreadSynchStrategy.h"

#include <ace/Reactor.h>

namespace OpenDDS { namespace DCPS {

class TransportSendStrategy;

/**
 * @class ReactorSynchStrategy
 *
 * @brief strategy to construct ReactorSynch implementations of ThreadSynch.
 *
 * This class is used as a factory for ReactorSynch objects that can be
 * used to scheduled queued output for processing on a reactor.  The
 * initial implementation will share the Transport reactor for all of the
 * sending and receiving processing to be performed.  If the reactor is
 * upgraded to a thread pool reactor, then this processing can be split
 * between those threads using the default leader-follower dispatching.
 *
 * The usage idiom for ThreadSynchStrategy ensures that his object will
 * have valid raw pointer values during its lifetime.
 */
class OpenDDS_Dcps_Export ReactorSynchStrategy : public ThreadSynchStrategy {
public:

  /// Construct with strategy, reactor, and handle to configure the
  /// ReactorSynch with.
  ReactorSynchStrategy( TransportSendStrategy* strategy,
                        ACE_Reactor* reactor);

  virtual ~ReactorSynchStrategy();

  virtual ThreadSynch* create_synch_object(
    ThreadSynchResource* synch_resource,
    long                 priority = 0,
    int                  scheduler = 0);

  private:
    /// Raw pointer to the strategy.  This is the strategy that contains
    /// the TreadSynch (which will receive this pointer) so the lifetime
    /// is assured.
    TransportSendStrategy* strategy_;

    /// Raw pointer to reactor.  This is ok since the strategy will pass
    /// the pointer on to the ReactorSynch, which is guaranteed to span
    /// the lifetime of both the strategy and the reactor.
    ACE_Reactor* reactor_;
};

}} // end namespace OpenDDS::DCPS

#if defined (__ACE_INLINE__)
#include "ReactorSynchStrategy.inl"
#endif /* __ACE_INLINE__ */

#endif  /* OPENDDS_DCPS_REACTORSYNCHSTRATEGY_H */

