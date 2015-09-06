/*
 * $Id: DataReaderCallbacks.h 6845 2015-01-22 23:17:55Z wilsonj $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_DATAREADERCALLBACKS_H
#define OPENDDS_DCPS_DATAREADERCALLBACKS_H

#include "dds/DCPS/Definitions.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace OpenDDS {
namespace DCPS {

/**
* @class DataReaderCallbacks
*
* @brief Defines the interface for Discovery callbacks into the DataReader.
*
*/
class DataReaderCallbacks {
public:

  DataReaderCallbacks() {}

  virtual ~DataReaderCallbacks() {}

  virtual void add_association(const RepoId& yourId,
                               const WriterAssociation& writer,
                               bool active) = 0;

  virtual void association_complete(const RepoId& remote_id) = 0;

  virtual void remove_associations(const WriterIdSeq& writers,
                                   CORBA::Boolean callback) = 0;

  virtual void update_incompatible_qos(const IncompatibleQosStatus& status) = 0;

  virtual void inconsistent_topic() = 0;

  virtual void signal_liveliness(const RepoId& remote_participant) = 0;
};

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_DCPS_DATAREADERCALLBACKS_H  */
