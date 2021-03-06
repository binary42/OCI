/* -*- C++ -*- */
/* Generated by ../bin/opendds_idl version 3.6 (ACE version 6.2a_p7) running on input file CorbaSeq/LongSeq.idl*/
#ifndef OPENDDS_IDL_GENERATED_LONGSEQTYPESUPPORTIMPL_H_FFZQ4Q
#define OPENDDS_IDL_GENERATED_LONGSEQTYPESUPPORTIMPL_H_FFZQ4Q
#include "dds/DCPS/Definitions.h"
#include "tao/LongSeqC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/dcps_export.h"


/* Begin MODULE: CORBA */



/* Begin TYPEDEF: LongSeq */

namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const CORBA::LongSeq& seq, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const CORBA::LongSeq& seq);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, CORBA::LongSeq& seq);

}  }

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_skip_over(Serializer& ser, CORBA::LongSeq*);

}  }

#endif

/* End TYPEDEF: LongSeq */

/* End MODULE: CORBA */
#endif /* OPENDDS_IDL_GENERATED_LONGSEQTYPESUPPORTIMPL_H_FFZQ4Q */
