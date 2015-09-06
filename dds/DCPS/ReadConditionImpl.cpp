/*
 * $Id: ReadConditionImpl.cpp 5426 2012-03-09 14:45:00Z calabrese_p $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "ReadConditionImpl.h"
#include "DataReaderImpl.h"

namespace OpenDDS {
namespace DCPS {

CORBA::Boolean ReadConditionImpl::get_trigger_value()
{
  return parent_->contains_sample(sample_states_,
                                  view_states_, instance_states_);
}

DDS::SampleStateMask ReadConditionImpl::get_sample_state_mask()
{
  return sample_states_;
}

DDS::ViewStateMask ReadConditionImpl::get_view_state_mask()
{
  return view_states_;
}

DDS::InstanceStateMask ReadConditionImpl::get_instance_state_mask()
{
  return instance_states_;
}

DDS::DataReader_ptr ReadConditionImpl::get_datareader()
{
  return DDS::DataReader::_duplicate(parent_);
}

} // namespace DCPS
} // namespace OpenDDS
