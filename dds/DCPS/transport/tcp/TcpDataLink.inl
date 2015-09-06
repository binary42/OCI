/*
 * $Id: TcpDataLink.inl 6668 2014-12-16 23:12:47Z oschwaldp $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "TcpTransport.h"
#include "TcpConnection.h"
#include "dds/DCPS/transport/framework/EntryExit.h"

ACE_INLINE const ACE_INET_Addr&
OpenDDS::DCPS::TcpDataLink::remote_address() const
{
  DBG_ENTRY_LVL("TcpDataLink","remote_address",6);
  return this->remote_address_;
}

ACE_INLINE OpenDDS::DCPS::TcpConnection_rch
OpenDDS::DCPS::TcpDataLink::get_connection()
{
  return this->connection_;
}

ACE_INLINE OpenDDS::DCPS::TcpTransport_rch
OpenDDS::DCPS::TcpDataLink::get_transport_impl()
{
  return this->transport_;
}

ACE_INLINE
bool
OpenDDS::DCPS::TcpDataLink::issues_on_deleted_callback() const
{
  return true;
}
