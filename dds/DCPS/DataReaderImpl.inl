/*
 * $Id: DataReaderImpl.inl 5871 2012-11-08 22:29:43Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

ACE_INLINE
DDS::DataReader_ptr
OpenDDS::DCPS::DataReaderImpl::get_dr_obj_ref()
{
  return DDS::DataReader::_duplicate(dr_local_objref_.in()) ;
}



ACE_INLINE
const OpenDDS::DCPS::DataReaderImpl::StatsMapType&
OpenDDS::DCPS::DataReaderImpl::raw_latency_statistics() const
{
  return this->statistics_;
}

ACE_INLINE
unsigned int&
OpenDDS::DCPS::DataReaderImpl::raw_latency_buffer_size()
{
  return this->raw_latency_buffer_size_;
}

ACE_INLINE
OpenDDS::DCPS::DataCollector<double>::OnFull&
OpenDDS::DCPS::DataReaderImpl::raw_latency_buffer_type()
{
  return this->raw_latency_buffer_type_;
}

ACE_INLINE
void
OpenDDS::DCPS::DataReaderImpl::disable_transport()
{
  this->transport_disabled_ = true;
}
