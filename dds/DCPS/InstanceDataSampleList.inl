/*
 * $Id: InstanceDataSampleList.inl 6393 2014-07-11 15:14:36Z oschwaldp $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */
#include "DataSampleElement.h"
#include <algorithm>

namespace OpenDDS {
namespace DCPS {


ACE_INLINE
InstanceDataSampleList::InstanceDataSampleList()
  : head_(0),
    tail_(0),
    size_(0)
{
}

ACE_INLINE
void InstanceDataSampleList::reset()
{
  head_ = tail_ = 0;
  size_ = 0;
}

ACE_INLINE
ssize_t
InstanceDataSampleList::size() const
{
  return size_;
}

ACE_INLINE
DataSampleElement*
InstanceDataSampleList::head() const
{
  return head_;
}

ACE_INLINE
DataSampleElement*
InstanceDataSampleList::tail() const
{
  return tail_;
}

ACE_INLINE
void
InstanceDataSampleList::enqueue_tail(const DataSampleElement* sample)
{
  // const_cast here so that higher layers don't need to pass around so many
  // non-const pointers to DataSampleElement.  Ideally the design would be
  // changed to accommodate const-correctness throughout.
  DataSampleElement* mSample = const_cast<DataSampleElement*>(sample);

  mSample->next_instance_sample_ = 0;

  ++ size_ ;

  if (head_ == 0) {
    // First sample on queue.
    head_ = tail_ = mSample ;

  } else {
    // Another sample on an existing queue.
    tail_->next_instance_sample_ = mSample ;
    tail_ = mSample ;
  }
}

ACE_INLINE
bool
InstanceDataSampleList::dequeue_head(DataSampleElement*& stale)
{
  //
  // Remove the oldest sample from the instance list.
  //
  stale = head_;

  if (head_ == 0) {
    // try to dequeue empty instance list.
    return false;

  } else {
    --size_ ;
    head_ = head_->next_instance_sample_ ;

    if (head_ == 0) {
      tail_ = 0;
    }

    stale->next_instance_sample_ = 0;
    return true;
  }
}

} // namespace DCPS
} // namespace OpenDDS
