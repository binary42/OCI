// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2a_p7
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:376

#include "DCPS/DdsDcps_pch.h"
#include "DdsDcpsGuidC.h"
#include "tao/CDR.h"

#if !defined (__ACE_INLINE__)
#include "DdsDcpsGuidC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_array/array_cs.cpp:97

OpenDDS::DCPS::GuidVendorId_t_slice *
OpenDDS::DCPS::GuidVendorId_t_dup (const OpenDDS::DCPS::GuidVendorId_t_slice *_tao_src_array)
{
  OpenDDS::DCPS::GuidVendorId_t_slice *_tao_dup_array =
    OpenDDS::DCPS::GuidVendorId_t_alloc ();
  
  if (!_tao_dup_array)
    {
      return static_cast <OpenDDS::DCPS::GuidVendorId_t_slice *> (0);
    }
  
  OpenDDS::DCPS::GuidVendorId_t_copy (_tao_dup_array, _tao_src_array);
  return _tao_dup_array;
}

OpenDDS::DCPS::GuidVendorId_t_slice *
OpenDDS::DCPS::GuidVendorId_t_alloc (void)
{
  OpenDDS::DCPS::GuidVendorId_t_slice *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::Octet[2], 0);
  return retval;
}

void
OpenDDS::DCPS::GuidVendorId_t_free (
    OpenDDS::DCPS::GuidVendorId_t_slice *_tao_slice)
{
  delete [] _tao_slice;
}

void
OpenDDS::DCPS::GuidVendorId_t_copy (
    OpenDDS::DCPS::GuidVendorId_t_slice * _tao_to,
    const OpenDDS::DCPS::GuidVendorId_t_slice *_tao_from)
{
  // Copy each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 2; ++i0)
    {
      _tao_to[i0] = _tao_from[i0];
    }
}

// TAO_IDL - Generated from
// be/be_visitor_array/array_cs.cpp:97

OpenDDS::DCPS::GuidPrefix_t_slice *
OpenDDS::DCPS::GuidPrefix_t_dup (const OpenDDS::DCPS::GuidPrefix_t_slice *_tao_src_array)
{
  OpenDDS::DCPS::GuidPrefix_t_slice *_tao_dup_array =
    OpenDDS::DCPS::GuidPrefix_t_alloc ();
  
  if (!_tao_dup_array)
    {
      return static_cast <OpenDDS::DCPS::GuidPrefix_t_slice *> (0);
    }
  
  OpenDDS::DCPS::GuidPrefix_t_copy (_tao_dup_array, _tao_src_array);
  return _tao_dup_array;
}

OpenDDS::DCPS::GuidPrefix_t_slice *
OpenDDS::DCPS::GuidPrefix_t_alloc (void)
{
  OpenDDS::DCPS::GuidPrefix_t_slice *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::Octet[12], 0);
  return retval;
}

void
OpenDDS::DCPS::GuidPrefix_t_free (
    OpenDDS::DCPS::GuidPrefix_t_slice *_tao_slice)
{
  delete [] _tao_slice;
}

void
OpenDDS::DCPS::GuidPrefix_t_copy (
    OpenDDS::DCPS::GuidPrefix_t_slice * _tao_to,
    const OpenDDS::DCPS::GuidPrefix_t_slice *_tao_from)
{
  // Copy each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 12; ++i0)
    {
      _tao_to[i0] = _tao_from[i0];
    }
}

// TAO_IDL - Generated from
// be/be_visitor_array/array_cs.cpp:97

OpenDDS::DCPS::EntityKey_t_slice *
OpenDDS::DCPS::EntityKey_t_dup (const OpenDDS::DCPS::EntityKey_t_slice *_tao_src_array)
{
  OpenDDS::DCPS::EntityKey_t_slice *_tao_dup_array =
    OpenDDS::DCPS::EntityKey_t_alloc ();
  
  if (!_tao_dup_array)
    {
      return static_cast <OpenDDS::DCPS::EntityKey_t_slice *> (0);
    }
  
  OpenDDS::DCPS::EntityKey_t_copy (_tao_dup_array, _tao_src_array);
  return _tao_dup_array;
}

OpenDDS::DCPS::EntityKey_t_slice *
OpenDDS::DCPS::EntityKey_t_alloc (void)
{
  OpenDDS::DCPS::EntityKey_t_slice *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::Octet[3], 0);
  return retval;
}

void
OpenDDS::DCPS::EntityKey_t_free (
    OpenDDS::DCPS::EntityKey_t_slice *_tao_slice)
{
  delete [] _tao_slice;
}

void
OpenDDS::DCPS::EntityKey_t_copy (
    OpenDDS::DCPS::EntityKey_t_slice * _tao_to,
    const OpenDDS::DCPS::EntityKey_t_slice *_tao_from)
{
  // Copy each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 3; ++i0)
    {
      _tao_to[i0] = _tao_from[i0];
    }
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:73

#if !defined (_OPENDDS_DCPS_GUIDSEQ_CS_)
#define _OPENDDS_DCPS_GUIDSEQ_CS_

OpenDDS::DCPS::GUIDSeq::GUIDSeq (void)
{}

OpenDDS::DCPS::GUIDSeq::GUIDSeq (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        GUID_t
      > (max)
{}

OpenDDS::DCPS::GUIDSeq::GUIDSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    OpenDDS::DCPS::GUID_t * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        GUID_t
      >
    (max, length, buffer, release)
{}

OpenDDS::DCPS::GUIDSeq::GUIDSeq (
    const GUIDSeq &seq)
  : ::TAO::unbounded_value_sequence<
        GUID_t
      > (seq)
{}

OpenDDS::DCPS::GUIDSeq::~GUIDSeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_array/cdr_op_cs.cpp:166


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OpenDDS::DCPS::GuidVendorId_t_forany &_tao_array)
{
  return
    strm.write_octet_array (
        reinterpret_cast <const ACE_CDR::Octet *> (_tao_array.in ()),
        2);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OpenDDS::DCPS::GuidVendorId_t_forany &_tao_array)
{
  return
    strm.read_octet_array (
        reinterpret_cast <ACE_CDR::Octet *> (_tao_array.out ()),
        2);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_array/cdr_op_cs.cpp:166


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OpenDDS::DCPS::GuidPrefix_t_forany &_tao_array)
{
  return
    strm.write_octet_array (
        reinterpret_cast <const ACE_CDR::Octet *> (_tao_array.in ()),
        12);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OpenDDS::DCPS::GuidPrefix_t_forany &_tao_array)
{
  return
    strm.read_octet_array (
        reinterpret_cast <ACE_CDR::Octet *> (_tao_array.out ()),
        12);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_array/cdr_op_cs.cpp:166


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OpenDDS::DCPS::EntityKey_t_forany &_tao_array)
{
  return
    strm.write_octet_array (
        reinterpret_cast <const ACE_CDR::Octet *> (_tao_array.in ()),
        3);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OpenDDS::DCPS::EntityKey_t_forany &_tao_array)
{
  return
    strm.read_octet_array (
        reinterpret_cast <ACE_CDR::Octet *> (_tao_array.out ()),
        3);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_cs.cpp:52

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OpenDDS::DCPS::EntityId_t &_tao_aggregate)
{
  OpenDDS::DCPS::EntityKey_t_forany _tao_aggregate_entityKey
      #if defined __IBMCPP__ && __IBMCPP__ <= 800
      ((OpenDDS::DCPS::EntityKey_t_slice*) (
      #else
      (const_cast<
          OpenDDS::DCPS::EntityKey_t_slice*> (
      #endif
          _tao_aggregate.entityKey
        )
    );
  return
    (strm << _tao_aggregate_entityKey) &&
    (strm << ::ACE_OutputCDR::from_octet (_tao_aggregate.entityKind));
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OpenDDS::DCPS::EntityId_t &_tao_aggregate)
{
  OpenDDS::DCPS::EntityKey_t_forany _tao_aggregate_entityKey
      #if defined __IBMCPP__ && __IBMCPP__ <= 800
      ((OpenDDS::DCPS::EntityKey_t_slice*) (
      #else
      (const_cast<
          OpenDDS::DCPS::EntityKey_t_slice*> (
      #endif
          _tao_aggregate.entityKey
        )
    );
  return
    (strm >> _tao_aggregate_entityKey) &&
    (strm >> ::ACE_InputCDR::to_octet (_tao_aggregate.entityKind));
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_cs.cpp:52

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OpenDDS::DCPS::GUID_t &_tao_aggregate)
{
  OpenDDS::DCPS::GuidPrefix_t_forany _tao_aggregate_guidPrefix
      #if defined __IBMCPP__ && __IBMCPP__ <= 800
      ((OpenDDS::DCPS::GuidPrefix_t_slice*) (
      #else
      (const_cast<
          OpenDDS::DCPS::GuidPrefix_t_slice*> (
      #endif
          _tao_aggregate.guidPrefix
        )
    );
  return
    (strm << _tao_aggregate_guidPrefix) &&
    (strm << _tao_aggregate.entityId);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OpenDDS::DCPS::GUID_t &_tao_aggregate)
{
  OpenDDS::DCPS::GuidPrefix_t_forany _tao_aggregate_guidPrefix
      #if defined __IBMCPP__ && __IBMCPP__ <= 800
      ((OpenDDS::DCPS::GuidPrefix_t_slice*) (
      #else
      (const_cast<
          OpenDDS::DCPS::GuidPrefix_t_slice*> (
      #endif
          _tao_aggregate.guidPrefix
        )
    );
  return
    (strm >> _tao_aggregate_guidPrefix) &&
    (strm >> _tao_aggregate.entityId);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:96
#if !defined _TAO_CDR_OP_OpenDDS_DCPS_GUIDSeq_CPP_
#define _TAO_CDR_OP_OpenDDS_DCPS_GUIDSeq_CPP_

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const OpenDDS::DCPS::GUIDSeq &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    OpenDDS::DCPS::GUIDSeq &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* _TAO_CDR_OP_OpenDDS_DCPS_GUIDSeq_CPP_ */

