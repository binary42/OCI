/*
 * $Id: DataLinkSet.cpp 6605 2014-11-19 19:33:47Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "DataLinkSet.h"
#include "DataLinkSet_rch.h"

#include "dds/DCPS/GuidConverter.h"
#include "dds/DCPS/Util.h"
#include "TransportImpl.h"
#include "TransportSendListener.h"

#include "EntryExit.h"

#if !defined (__ACE_INLINE__)
#include "DataLinkSet.inl"
#endif /* __ACE_INLINE__ */

//TBD: The number of chunks in send control cached allocator and map
//     entry allocator are hard coded for now. These values will be
//     configured when we implement the dds configurations.

/// The number of chuncks in send control cached allocator per pub/sub.
#define NUM_SEND_CONTROL_ELEMENT_CHUNKS 20

OpenDDS::DCPS::DataLinkSet::DataLinkSet()
  : send_control_element_allocator_(NUM_SEND_CONTROL_ELEMENT_CHUNKS)
  , send_response_listener_("DataLinkSet")
{
  DBG_ENTRY_LVL("DataLinkSet","DataLinkSet",6);

  if (OpenDDS::DCPS::Transport_debug_level >= 2) {
    ACE_DEBUG((LM_DEBUG, "(%P|%t) DataLinkSet send_control_element_allocator %x with %d chunks\n",
               &send_control_element_allocator_, NUM_SEND_CONTROL_ELEMENT_CHUNKS));
  }
}

OpenDDS::DCPS::DataLinkSet::~DataLinkSet()
{
  DBG_ENTRY_LVL("DataLinkSet","~DataLinkSet",6);
}

int
OpenDDS::DCPS::DataLinkSet::insert_link(DataLink* link)
{
  DBG_ENTRY_LVL("DataLinkSet","insert_link",6);
  DataLink_rch mylink(link, false);
  GuardType guard(this->lock_);
  return OpenDDS::DCPS::bind(map_, mylink->id(), mylink);
}

void
OpenDDS::DCPS::DataLinkSet::remove_link(const DataLink_rch& link)
{
  DBG_ENTRY_LVL("DataLinkSet", "remove_link", 6);
  GuardType guard1(this->lock_);
  if (unbind(map_, link->id()) != 0) {
    // Just report to the log that we tried.
    VDBG((LM_DEBUG,
          ACE_TEXT("(%P|%t) DataLinkSet::remove_links: ")
          ACE_TEXT("link_id %d not found in map.\n"),
          link->id()));
  }
}

OpenDDS::DCPS::DataLinkSet*
OpenDDS::DCPS::DataLinkSet::select_links(const RepoId* remoteIds,
                                         const CORBA::ULong num_targets)
{
  DBG_ENTRY_LVL("DataLinkSet","select_links",6);

  DataLinkSet_rch selected_links = new DataLinkSet();
  GuardType guard(this->lock_);
  for (MapType::iterator itr = map_.begin();
       itr != map_.end();
       ++itr) {
    for (CORBA::ULong i = 0; i < num_targets; ++i) {
      if (itr->second->is_target(remoteIds[i])) {
        OpenDDS::DCPS::bind(selected_links->map_,
             itr->second->id(), itr->second);
        break;
      }
    }
  }

  return selected_links._retn();
}

bool
OpenDDS::DCPS::DataLinkSet::empty()
{
  GuardType guard(this->lock_);

  return map_.empty();
}
