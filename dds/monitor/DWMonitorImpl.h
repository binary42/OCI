/*
 * $Id: DWMonitorImpl.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_DW_MONITOR_IMPL_H
#define OPENDDS_DCPS_DW_MONITOR_IMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace OpenDDS {
namespace DCPS {

class DWMonitorImpl : public Monitor {
public:
  DWMonitorImpl(DataWriterImpl* dw,
                   OpenDDS::DCPS::DataWriterReportDataWriter_ptr dw_writer);
  virtual ~DWMonitorImpl();
  virtual void report();

private:
  DataWriterImpl* dw_;
  OpenDDS::DCPS::DataWriterReportDataWriter_var dw_writer_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_DCPS_DW_MONITOR_IMPL_H */
