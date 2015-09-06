/*
 * $Id: RepoIdBuilder.inl 5266 2012-01-21 04:36:48Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

namespace OpenDDS {
namespace DCPS {

ACE_INLINE void
RepoIdBuilder::federationId(long federationId)
{
  guidPrefix1(federationId);
}

ACE_INLINE void
RepoIdBuilder::participantId(long participantId)
{
  guidPrefix2(participantId);
}


} // namespace DCPS
} // namespace OpenDDS
