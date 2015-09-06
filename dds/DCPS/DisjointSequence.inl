/*
 * $Id: DisjointSequence.inl 5266 2012-01-21 04:36:48Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

namespace OpenDDS {
namespace DCPS {

ACE_INLINE SequenceNumber
DisjointSequence::low() const
{
  return sequences_.begin()->first;
}

ACE_INLINE SequenceNumber
DisjointSequence::high() const
{
  return sequences_.rbegin()->second;
}

ACE_INLINE SequenceNumber
DisjointSequence::cumulative_ack() const
{
  return sequences_.empty()
    ? SequenceNumber::SEQUENCENUMBER_UNKNOWN()
    : sequences_.begin()->second;
}

ACE_INLINE SequenceNumber
DisjointSequence::last_ack() const
{
  return sequences_.empty()
    ? SequenceNumber::SEQUENCENUMBER_UNKNOWN()
    : sequences_.rbegin()->first;
}

ACE_INLINE bool
DisjointSequence::empty() const
{
  return sequences_.empty();
}

ACE_INLINE bool
DisjointSequence::disjoint() const
{
  return sequences_.size() > 1;
}

ACE_INLINE
DisjointSequence::DisjointSequence()
  : sequences_(SequenceRange_LessThan)
{
}

ACE_INLINE void
DisjointSequence::reset()
{
  sequences_.clear();
}

ACE_INLINE bool
DisjointSequence::insert(SequenceNumber value)
{
  return insert_i(SequenceRange(value, value));
}

ACE_INLINE bool
DisjointSequence::insert(const SequenceRange& range)
{
  return insert_i(range);
}

ACE_INLINE bool
DisjointSequence::insert(const SequenceRange& range,
                         std::vector<SequenceRange>& gaps)
{
  return insert_i(range, &gaps);
}

} // namespace DCPS
} // namespace OpenDDS
