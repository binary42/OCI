/*
 * $Id: TransportInst.cpp 5770 2012-08-17 21:04:27Z harrisb $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "TransportInst.h"
#include "TransportImpl.h"
#include "TransportExceptions.h"
#include "EntryExit.h"

#include "ace/Configuration.h"

#include <iomanip>
#include <sstream>

#if !defined (__ACE_INLINE__)
# include "TransportInst.inl"
#endif /* !__ACE_INLINE__ */

OpenDDS::DCPS::TransportInst::~TransportInst()
{
  DBG_ENTRY_LVL("TransportInst","~TransportInst",6);
}

int
OpenDDS::DCPS::TransportInst::load(ACE_Configuration_Heap& cf,
                                   ACE_Configuration_Section_Key& sect)
{
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("queue_messages_per_pool"), this->queue_messages_per_pool_, size_t)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("queue_initial_pools"), this->queue_initial_pools_, size_t)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("max_packet_size"), this->max_packet_size_, ACE_UINT32)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("max_samples_per_packet"), this->max_samples_per_packet_, size_t)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("optimum_packet_size"), this->optimum_packet_size_, ACE_UINT32)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("thread_per_connection"), this->thread_per_connection_, bool)
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("datalink_release_delay"), this->datalink_release_delay_, int)

  // Undocumented - this option is not in the Developer's Guide
  // Controls the number of chunks in the allocators used by the datalink
  // for control messages.
  GET_CONFIG_VALUE(cf, sect, ACE_TEXT("datalink_control_chunks"), this->datalink_control_chunks_, size_t)

  ACE_TString stringvalue;
  if (cf.get_string_value (sect, ACE_TEXT("passive_connect_duration"), stringvalue) == 0) {
    ACE_DEBUG ((LM_WARNING,
                ACE_TEXT ("(%P|%t) WARNING: passive_connect_duration option ")
                ACE_TEXT ("is deprecated in the transport inst, must be ")
                ACE_TEXT ("defined in transport config.\n")));
  }

  adjust_config_value();
  return 0;
}

void
OpenDDS::DCPS::TransportInst::dump()
{
  std::stringstream os;
  dump(os);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("\n(%P|%t) TransportInst::dump() -\n%C"),
             os.str().c_str()));
}

namespace {
  static const int NAME_INDENT(3);
  static const int NAME_WIDTH(30); // Includes ":"
}

std::string
OpenDDS::DCPS::TransportInst::formatNameForDump(const char* name)
{
  std::ostringstream oss;
  oss << std::setw(NAME_INDENT) << "" << std::setw(NAME_WIDTH) << std::left
      << name << ": ";
  return oss.str();
}

void
OpenDDS::DCPS::TransportInst::dump(std::ostream& os)
{
  os << formatNameForDump("transport_type")          << this->transport_type_ << std::endl;
  os << formatNameForDump("name")                    << this->name_ << std::endl;
  os << formatNameForDump("queue_messages_per_pool") << this->queue_messages_per_pool_ << std::endl;
  os << formatNameForDump("queue_initial_pools")     << this->queue_initial_pools_ << std::endl;
  os << formatNameForDump("max_packet_size")         << this->max_packet_size_ << std::endl;
  os << formatNameForDump("max_samples_per_packet")  << this->max_samples_per_packet_ << std::endl;
  os << formatNameForDump("optimum_packet_size")     << this->optimum_packet_size_ << std::endl;
  os << formatNameForDump("thread_per_connection")   << (this->thread_per_connection_ ? "true" : "false") << std::endl;
  os << formatNameForDump("datalink_release_delay")  << this->datalink_release_delay_ << std::endl;
  os << formatNameForDump("datalink_control_chunks") << this->datalink_control_chunks_ << std::endl;
}

void
OpenDDS::DCPS::TransportInst::shutdown()
{
  ACE_GUARD(ACE_SYNCH_MUTEX, g, this->lock_);
  if (!this->impl_.is_nil()) {
    this->impl_->shutdown();
    this->impl_ = 0;
  }
}

OpenDDS::DCPS::TransportImpl_rch
OpenDDS::DCPS::TransportInst::impl()
{
  ACE_GUARD_RETURN(ACE_SYNCH_MUTEX, g, this->lock_, TransportImpl_rch());
  if (this->impl_.is_nil()) {
    try {
      this->impl_ = this->new_impl(TransportInst_rch(this, false));
    } catch (const OpenDDS::DCPS::Transport::UnableToCreate& ) {
      return 0;
    }
  }
  return this->impl_;
}
