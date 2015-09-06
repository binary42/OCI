/*
 * $Id: PublisherMonitorImpl.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_PUBLISHER_MONITOR_IMPL_H
#define OPENDDS_DCPS_PUBLISHER_MONITOR_IMPL_H

#include "monitor_export.h"
#include "dds/DCPS/MonitorFactory.h"
#include "monitorTypeSupportImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace OpenDDS {
namespace DCPS {

class PublisherMonitorImpl : public Monitor {
public:
  PublisherMonitorImpl(PublisherImpl* pub,
                   OpenDDS::DCPS::PublisherReportDataWriter_ptr pub_writer);
  virtual ~PublisherMonitorImpl();
  virtual void report();

private:
  PublisherImpl* pub_;
  OpenDDS::DCPS::PublisherReportDataWriter_var pub_writer_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_DCPS_PUBLISHER_MONITOR_IMPL_H */
