/*
 * $Id: FederationId.h 6240 2014-06-04 16:54:28Z johnsonb $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef DCPS_IR_FEDERATOR_ID_H
#define DCPS_IR_FEDERATOR_ID_H

#include "inforepo_export.h"
#include "tao/Basic_Types.h"

class OpenDDS_InfoRepoLib_Export TAO_DDS_DCPSFederationId
{
public:
  typedef ::CORBA::Long RepoKey;
  TAO_DDS_DCPSFederationId(RepoKey initId);
  void id(RepoKey fedId);
  RepoKey id() const;
//  void overridden(bool overrideId);
  bool overridden() const;
private:
  RepoKey id_;
  bool    overridden_;
};

#endif /* DCPS_IR_FEDERATOR_ID_H */
