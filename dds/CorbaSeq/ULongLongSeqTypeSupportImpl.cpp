/* Generated by ../bin/opendds_idl version 3.6 (ACE version 6.2a_p7) running on input file CorbaSeq/ULongLongSeq.idl*/
#include "DCPS/DdsDcps_pch.h"
#include "ULongLongSeqTypeSupportImpl.h"

#include "dds/CorbaSeq/ULongLongSeqTypeSupportImpl.h"


/* Begin MODULE: CORBA */



/* Begin TYPEDEF: ULongLongSeq */

namespace OpenDDS { namespace DCPS {

void gen_find_size(const CORBA::ULongLongSeq& seq, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(seq);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  find_size_ulong(size, padding);
  if (seq.length() == 0) {
    return;
  }
  if ((size + padding) % 8) {
    padding += 4;
  }
  size += seq.length() * gen_max_marshaled_size(CORBA::ULongLong());
}

bool operator<<(Serializer& strm, const CORBA::ULongLongSeq& seq)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(seq);
  const CORBA::ULong length = seq.length();
  if (!(strm << length)) {
    return false;
  }
  if (length == 0) {
    return true;
  }
  return strm.write_ulonglong_array(seq.get_buffer(), length);
}

bool operator>>(Serializer& strm, CORBA::ULongLongSeq& seq)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(seq);
  CORBA::ULong length;
  if (!(strm >> length)) {
    return false;
  }
  seq.length(length);
  if (length == 0) {
    return true;
  }
  return strm.read_ulonglong_array(seq.get_buffer(), length);
}

}  }

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
namespace OpenDDS { namespace DCPS {

void gen_skip_over(Serializer& ser, CORBA::ULongLongSeq*)
{
  ACE_UNUSED_ARG(ser);
  ACE_CDR::ULong length;
  ser >> length;
  ser.skip(length, 8);
}

}  }

#endif

/* End TYPEDEF: ULongLongSeq */

/* End MODULE: CORBA */