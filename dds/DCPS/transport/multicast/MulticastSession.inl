/*
 * $Id: MulticastSession.inl 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

namespace OpenDDS {
namespace DCPS {

ACE_INLINE MulticastDataLink*
MulticastSession::link()
{
  return this->link_;
}

ACE_INLINE MulticastPeer
MulticastSession::remote_peer() const
{
  return this->remote_peer_;
}

} // namespace DCPS
} // namespace OpenDDS
