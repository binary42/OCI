/*
 * $Id: CoherentChangeControl.inl 5637 2012-06-01 19:32:59Z harrisb $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_NO_OBJECT_MODEL_PROFILE

namespace OpenDDS {
namespace DCPS {

ACE_INLINE
WriterCoherentSample::WriterCoherentSample (
  ACE_UINT32 num_sample,
  SequenceNumber last_sample)
  : num_samples_ (num_sample),
    last_sample_ (last_sample)
  {}


ACE_INLINE
void WriterCoherentSample::reset ()
{
  num_samples_ = 0;
  last_sample_ = SequenceNumber();
}


ACE_INLINE
CoherentChangeControl::CoherentChangeControl()
  : coherent_samples_ (),
    group_coherent_ (false),
    publisher_id_ (GUID_UNKNOWN)
{
}


ACE_INLINE
size_t
CoherentChangeControl::max_marshaled_size()
{
  size_t sz = sizeof(this->coherent_samples_)
              + sizeof(this->group_coherent_);
  if (this->group_coherent_) {
    sz += sizeof(this->publisher_id_);
    sz += sizeof (ACE_UINT32);
    sz += this->group_coherent_samples_.size () *
          (sizeof(PublicationId) + sizeof(this->coherent_samples_));
  }

  return sz;
}

ACE_INLINE
void
CoherentChangeControl::reset()
{
  this->coherent_samples_ = WriterCoherentSample();
  this->group_coherent_ = false;
  this->publisher_id_ = GUID_UNKNOWN;
  this->group_coherent_samples_.clear();
}

} // namespace DCPS
} // namespace OpenDDS

#endif // OPENDDS_NO_OBJECT_MODEL_PROFILE
