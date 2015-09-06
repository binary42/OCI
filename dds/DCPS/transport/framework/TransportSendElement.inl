/*
 * $Id: TransportSendElement.inl 6391 2014-07-10 15:32:25Z oschwaldp $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "EntryExit.h"

ACE_INLINE
OpenDDS::DCPS::TransportSendElement::TransportSendElement(int initial_count,
  const DataSampleElement* sample,
  TransportSendElementAllocator* allocator)
  : TransportQueueElement(initial_count),
    element_(sample),
    allocator_(allocator)
{
  DBG_ENTRY_LVL("TransportSendElement","TransportSendElement",6);
}

ACE_INLINE /*static*/
OpenDDS::DCPS::TransportSendElement*
OpenDDS::DCPS::TransportSendElement::alloc(int initial_count,
                                           const DataSampleElement* sample)
{
  TransportSendElement* ret;
  TransportSendElementAllocator* al = sample->get_transport_send_element_allocator();
  ACE_NEW_MALLOC_RETURN(ret,
    static_cast<TransportSendElement*>(al->malloc()),
    TransportSendElement(initial_count, sample, al),
    0);
  return ret;
}

ACE_INLINE
bool
OpenDDS::DCPS::TransportSendElement::owned_by_transport()
{
  return false;
}

ACE_INLINE
OpenDDS::DCPS::SequenceNumber
OpenDDS::DCPS::TransportSendElement::sequence() const
{
  return this->element_->get_header().sequence_;
}

ACE_INLINE
const OpenDDS::DCPS::DataSampleElement*
OpenDDS::DCPS::TransportSendElement::sample() const
{
  return this->element_;
}
