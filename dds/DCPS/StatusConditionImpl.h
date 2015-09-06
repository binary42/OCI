/*
 * $Id: StatusConditionImpl.h 5426 2012-03-09 14:45:00Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_STATUSCONDITIONIMPL_H
#define OPENDDS_DCPS_STATUSCONDITIONIMPL_H

#include "dds/DdsDcpsInfrastructureC.h"
#include "dds/DCPS/ConditionImpl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace OpenDDS {
namespace DCPS {

class EntityImpl;

class StatusConditionImpl
  : public virtual OpenDDS::DCPS::LocalObject<DDS::StatusCondition>
  , public virtual ConditionImpl {
public:
  explicit StatusConditionImpl(EntityImpl* e)
    : parent_(e)
    , mask_(::OpenDDS::DCPS::DEFAULT_STATUS_MASK)
  {}

  virtual ~StatusConditionImpl() {}

  CORBA::Boolean get_trigger_value();

  virtual DDS::StatusMask get_enabled_statuses();

  virtual DDS::ReturnCode_t set_enabled_statuses(DDS::StatusMask mask);

  virtual DDS::Entity_ptr get_entity();

private:
  //deliberately not a _var, don't hold a reference to the parent since
  //it is guaranteed to outlive us and we don't want a cyclical reference
  EntityImpl* parent_;
  DDS::StatusMask mask_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif
