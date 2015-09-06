/*
 * $Id: TransportConfig.h 6606 2014-11-20 17:16:02Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_TRANSPORTCONFIG_H
#define OPENDDS_DCPS_TRANSPORTCONFIG_H

#include <ace/config.h>
#ifndef ACE_LACKS_PRAGMA_ONCE
#pragma once
#endif

#include "dds/DCPS/dcps_export.h"
#include "dds/DCPS/RcObject_T.h"
#include "TransportInst.h"
#include "TransportInst_rch.h"

#include <ace/Synch_Traits.h>

#include <vector>
#include <string>

namespace OpenDDS {
namespace DCPS {

class OpenDDS_Dcps_Export TransportConfig : public RcObject<ACE_SYNCH_MUTEX> {
public:

  static const unsigned long DEFAULT_PASSIVE_CONNECT_DURATION = 60000;

  std::string name() const { return name_; }

  std::vector<TransportInst_rch> instances_;

  bool swap_bytes_;

  /// The time period in milliseconds for the acceptor side
  /// of a connection to wait for the connection.
  /// The default is 60 seconds
  unsigned long passive_connect_duration_;

  /// Insert the TransportInst in sorted order (by name) in the instances_ list.
  /// Use when the names of the TransportInst objects are specifically assigned
  /// to have the sorted order make sense.
  void sorted_insert(const TransportInst_rch& inst);

private:
  friend class TransportRegistry;
  explicit TransportConfig(const std::string& name);
  ~TransportConfig();

  const std::string name_;
};

}
}

#if defined(__ACE_INLINE__)
#include "TransportConfig.inl"
#endif /* __ACE_INLINE__ */

#endif /* OPENDDS_DCPS_TRANSPORTCONFIG_H */
