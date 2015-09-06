/*
 * $Id: TcpSynchResource.cpp 5266 2012-01-21 04:36:48Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "Tcp_pch.h"
#include "TcpSynchResource.h"
#include "TcpConnection.h"
#include "TcpSendStrategy.h"

OpenDDS::DCPS::TcpSynchResource::TcpSynchResource(
  const TcpConnection_rch& connection,
  const int& max_output_pause_period_ms)
  : ThreadSynchResource(connection->peer().get_handle())
  , connection_(connection)
{
  DBG_ENTRY_LVL("TcpSynchResource","TcpSynchResource",6);

  if (max_output_pause_period_ms >= 0) {
    this->timeout_ = new ACE_Time_Value(max_output_pause_period_ms / 1000,
                                        max_output_pause_period_ms % 1000 * 1000);
  }
}

OpenDDS::DCPS::TcpSynchResource::~TcpSynchResource()
{
  DBG_ENTRY_LVL("TcpSynchResource","~TcpSynchResource",6);
}

void
OpenDDS::DCPS::TcpSynchResource::notify_lost_on_backpressure_timeout()
{
  DBG_ENTRY_LVL("TcpSynchResource","notify_lost_on_backpressure_timeout",6);

  this->connection_->notify_lost_on_backpressure_timeout();
}
