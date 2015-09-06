/*
 * $Id: BestEffortSession.h 6893 2015-01-29 15:27:49Z wilsonj $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_BESTEFFORTSESSION_H
#define DCPS_BESTEFFORTSESSION_H

#include "Multicast_Export.h"

#include "MulticastSession.h"

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Multicast_Export BestEffortSession
  : public MulticastSession {
public:
  BestEffortSession(ACE_Reactor* reactor,
                    ACE_thread_t owner,
                    MulticastDataLink* link,
                    MulticastPeer remote_peer);

  virtual bool check_header(const TransportHeader& header);

  virtual bool start(bool active, bool acked);

private:
  SequenceNumber expected_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif  /* DCPS_BESTEFFORTSESSION_H */
