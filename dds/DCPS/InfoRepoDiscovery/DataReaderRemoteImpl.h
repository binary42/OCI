/*
 * $Id: DataReaderRemoteImpl.h 5526 2012-04-19 14:54:13Z johnsonb $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_DATAREADERREMOTEIMPL_H
#define OPENDDS_DCPS_DATAREADERREMOTEIMPL_H

#include "InfoRepoDiscovery_Export.h"
#include "DataReaderRemoteS.h"
#include "dds/DCPS/Definitions.h"

#include "ace/Thread_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace OpenDDS {
namespace DCPS {

class DataReaderCallbacks;

/**
* @class DataReaderRemoteImpl
*
* @brief Implements the OpenDDS::DCPS::ReaderRemote interface that
*        is used to add and remove associations.
*
*/
class DataReaderRemoteImpl
  : public virtual POA_OpenDDS::DCPS::DataReaderRemote {
public:

  explicit DataReaderRemoteImpl(DataReaderCallbacks* parent);

  virtual ~DataReaderRemoteImpl();

  virtual void add_association(const RepoId& yourId,
                               const WriterAssociation& writer,
                               bool active);

  virtual void association_complete(const RepoId& remote_id);

  virtual void remove_associations(const WriterIdSeq& writers,
                                   CORBA::Boolean callback);

  virtual void update_incompatible_qos(const IncompatibleQosStatus& status);

  void detach_parent();

private:
  DataReaderCallbacks* parent_;
  ACE_Thread_Mutex mutex_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif /* OPENDDS_DCPS_DATAREADERREMOTEIMPL_H  */
