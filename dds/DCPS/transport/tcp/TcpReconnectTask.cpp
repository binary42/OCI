/*
 * $Id: TcpReconnectTask.cpp 4836 2011-08-06 01:11:10Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "Tcp_pch.h"
#include "TcpReconnectTask.h"
#include "TcpConnection.h"
#include "TcpSendStrategy.h"
#include "dds/DCPS/transport/framework/EntryExit.h"

OpenDDS::DCPS::TcpReconnectTask::TcpReconnectTask(
  OpenDDS::DCPS::TcpConnection* connection)
  : connection_(connection)
{
  DBG_ENTRY_LVL("TcpReconnectTask","TcpReconnectTask",6);
}

OpenDDS::DCPS::TcpReconnectTask::~TcpReconnectTask()
{
  DBG_ENTRY_LVL("TcpReconnectTask","~TcpReconnectTask",6);
}

void OpenDDS::DCPS::TcpReconnectTask::execute(ReconnectOpType& op)
{
  DBG_ENTRY_LVL("TcpReconnectTask","execute",6);

  // Ignore all signals to avoid
  //     ERROR: <something descriptive> Interrupted system call
  // The main thread will handle signals.
  sigset_t set;
  ACE_OS::sigfillset(&set);
  ACE_OS::thr_sigsetmask(SIG_SETMASK, &set, NULL);

  if (op == DO_RECONNECT) {
    if (this->connection_->reconnect() == -1) {
      this->connection_->tear_link();
    }

  } else
    ACE_ERROR((LM_ERROR, "(%P|%t) ERROR: TcpReconnectTask::svc unknown operation %d\n", op));
}
