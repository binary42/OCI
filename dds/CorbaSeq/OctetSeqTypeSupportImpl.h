/* -*- C++ -*- */
/* Generated by ../bin/opendds_idl version 3.6 (ACE version 6.2a_p7) running on input file CorbaSeq/OctetSeq.idl*/
#ifndef OPENDDS_IDL_GENERATED_OCTETSEQTYPESUPPORTIMPL_H_QRUVIO
#define OPENDDS_IDL_GENERATED_OCTETSEQTYPESUPPORTIMPL_H_QRUVIO
#include "dds/DCPS/Definitions.h"
#include "tao/OctetSeqC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/dcps_export.h"


/* Begin MODULE: CORBA */



/* Begin TYPEDEF: OctetSeq */

namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const CORBA::OctetSeq& seq, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const CORBA::OctetSeq& seq);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, CORBA::OctetSeq& seq);

}  }

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_skip_over(Serializer& ser, CORBA::OctetSeq*);

}  }

#endif

/* End TYPEDEF: OctetSeq */

/* End MODULE: CORBA */
#endif /* OPENDDS_IDL_GENERATED_OCTETSEQTYPESUPPORTIMPL_H_QRUVIO */