/*
 * $Id: NetworkAddress.cpp 5943 2013-03-03 18:39:03Z johnnyw $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#include "DCPS/DdsDcps_pch.h" //Only the _pch include should start with DCPS/
#include "NetworkAddress.h"
#include "ace/OS_NS_netdb.h"
#include "ace/Sock_Connect.h"

#if !defined (__ACE_INLINE__)
# include "NetworkAddress.inl"
#endif /* !__ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_CDR::Boolean
operator<< (ACE_OutputCDR& outCdr, OpenDDS::DCPS::NetworkAddress& value)
{
  outCdr << ACE_OutputCDR::from_boolean(ACE_CDR_BYTE_ORDER);

  outCdr << ACE_OutputCDR::from_octet(value.reserved_);
  outCdr << value.addr_.c_str();

  return outCdr.good_bit();
}

ACE_CDR::Boolean
operator>> (ACE_InputCDR& inCdr, OpenDDS::DCPS::NetworkAddress& value)
{
  CORBA::Boolean byte_order;

  if (inCdr >> ACE_InputCDR::to_boolean(byte_order) == 0)
    return 0;

  inCdr.reset_byte_order(byte_order);

  if (inCdr >> ACE_InputCDR::to_octet(value.reserved_) == 0)
    return 0;

  char* buf = 0;

  if (inCdr >> buf == 0)
    return 0;

  value.addr_ = buf;

  delete[] buf;

  return inCdr.good_bit();
}

ACE_END_VERSIONED_NAMESPACE_DECL

namespace OpenDDS {
namespace DCPS {

std::string get_fully_qualified_hostname(ACE_INET_Addr* addr)
{
  // cache the determined fully qualified hostname and its
  // address to be used on subsequent calls
  static std::string fullname;
  static ACE_INET_Addr selected_address;

  if (fullname.length() == 0) {
    size_t addr_count;
    ACE_INET_Addr *addr_array;
    OpenDDS::DCPS::HostnameInfoVector nonFQDN;

    int result = ACE::get_ip_interfaces(addr_count, addr_array);

    struct Array_Guard {
      Array_Guard(ACE_INET_Addr *ptr) : ptr_(ptr) {}
      ~Array_Guard() {
        delete [] ptr_;
      }
      ACE_INET_Addr* const ptr_;
    } guardObject(addr_array);

    if (result != 0 || addr_count < 1) {
      ACE_ERROR((LM_ERROR,
                 ACE_TEXT("(%P|%t) ERROR: Unable to probe network. %p\n"),
                 ACE_TEXT("ACE::get_ip_interfaces")));

    } else {
      for (size_t i = 0; i < addr_count; i++) {
        char hostname[MAXHOSTNAMELEN+1] = "";

        //Discover the fully qualified hostname

        if (ACE::get_fqdn(addr_array[i], hostname, MAXHOSTNAMELEN+1) == 0) {
          if (addr_array[i].is_loopback() == false && ACE_OS::strchr(hostname, '.') != 0) {
            VDBG_LVL((LM_DEBUG, "(%P|%t) found fqdn %C from %C:%d\n",
                      hostname, addr_array[i].get_host_addr(), addr_array[i].get_port_number()), 2);
            selected_address = addr_array[i];
            fullname = hostname;
            if (addr) {
              *addr = selected_address;
            }
            return fullname;

          } else {
            VDBG_LVL((LM_DEBUG, "(%P|%t) ip interface %C:%d maps to hostname %C\n",
                      addr_array[i].get_host_addr(), addr_array[i].get_port_number(), hostname), 2);

            if (ACE_OS::strncmp(hostname, "localhost", 9) == 0) {
              addr_array[i].get_host_addr(hostname, MAXHOSTNAMELEN);
            }

            OpenDDS::DCPS::HostnameInfo info;
            info.index_ = i;
            info.hostname_ = hostname;
            nonFQDN.push_back(info);
          }
        }
      }
    }

    OpenDDS::DCPS::HostnameInfoVector::iterator itBegin = nonFQDN.begin();
    OpenDDS::DCPS::HostnameInfoVector::iterator itEnd = nonFQDN.end();

    for (OpenDDS::DCPS::HostnameInfoVector::iterator it = itBegin; it != itEnd; ++it) {
      if (addr_array[it->index_].is_loopback() == false) {
        ACE_DEBUG((LM_WARNING, "(%P|%t) WARNING: Could not find FQDN. Using "
                   "\"%C\" as fully qualified hostname, please "
                   "correct system configuration.\n", it->hostname_.c_str()));
        selected_address = addr_array[it->index_];
        fullname = it->hostname_;
        if (addr) {
          *addr = selected_address;
        }
        return fullname;
      }
    }

    if (itBegin != itEnd) {
      ACE_DEBUG((LM_WARNING, "(%P|%t) WARNING: Could not find FQDN. Using "
                 "\"%C\" as fully qualified hostname, please "
                 "correct system configuration.\n", itBegin->hostname_.c_str()));
      selected_address = addr_array[itBegin->index_];
      fullname = itBegin->hostname_;
      if (addr) {
        *addr = selected_address;
      }
      return fullname;
    }

    ACE_ERROR((LM_ERROR,
               "(%P|%t) ERROR: failed to discover the fully qualified hostname\n"));
  }

  if (addr) {
    *addr = selected_address;
  }
  return fullname;
}

}
}
