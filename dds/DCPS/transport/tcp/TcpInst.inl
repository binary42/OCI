/*
 * $Id: TcpInst.inl 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "dds/DCPS/transport/framework/EntryExit.h"

ACE_INLINE
OpenDDS::DCPS::TcpInst::TcpInst(const std::string& name)
  : TransportInst("tcp", name),
    enable_nagle_algorithm_(false),
    conn_retry_initial_delay_(500),
    conn_retry_backoff_multiplier_(2.0),
    conn_retry_attempts_(3),
    max_output_pause_period_(-1),
    passive_reconnect_duration_(2000)
{
  DBG_ENTRY_LVL("TcpInst", "TcpInst", 6);
}
