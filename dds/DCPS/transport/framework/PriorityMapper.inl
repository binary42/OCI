/*
 * $Id: PriorityMapper.inl 6605 2014-11-19 19:33:47Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

namespace OpenDDS {
namespace DCPS {

ACE_INLINE
PriorityMapper::PriorityMapper(Priority priority)
  : priority_(priority)
{
}

ACE_INLINE
Priority&
PriorityMapper::priority()
{
  return this->priority_;
}

ACE_INLINE
Priority
PriorityMapper::priority() const
{
  return this->priority_;
}

}
}
