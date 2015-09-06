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
#include "DdsDcpsTypeSupportExtC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "DdsDcpsTypeSupportExtC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:51

// Traits specializations for OpenDDS::DCPS::TypeSupport.

OpenDDS::DCPS::TypeSupport_ptr
TAO::Objref_Traits<OpenDDS::DCPS::TypeSupport>::duplicate (
    OpenDDS::DCPS::TypeSupport_ptr p)
{
  return OpenDDS::DCPS::TypeSupport::_duplicate (p);
}

void
TAO::Objref_Traits<OpenDDS::DCPS::TypeSupport>::release (
    OpenDDS::DCPS::TypeSupport_ptr p)
{
  ::CORBA::release (p);
}

OpenDDS::DCPS::TypeSupport_ptr
TAO::Objref_Traits<OpenDDS::DCPS::TypeSupport>::nil (void)
{
  return OpenDDS::DCPS::TypeSupport::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<OpenDDS::DCPS::TypeSupport>::marshal (
    const OpenDDS::DCPS::TypeSupport_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

OpenDDS::DCPS::TypeSupport::TypeSupport (void)
{}

OpenDDS::DCPS::TypeSupport::~TypeSupport (void)
{
}

OpenDDS::DCPS::TypeSupport_ptr
OpenDDS::DCPS::TypeSupport::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return TypeSupport::_duplicate (
      dynamic_cast<TypeSupport_ptr> (_tao_objref)
    );
}

OpenDDS::DCPS::TypeSupport_ptr
OpenDDS::DCPS::TypeSupport::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return TypeSupport::_duplicate (
      dynamic_cast<TypeSupport_ptr> (_tao_objref)
    );
}

OpenDDS::DCPS::TypeSupport_ptr
OpenDDS::DCPS::TypeSupport::_nil (void)
{
  return 0;
}

OpenDDS::DCPS::TypeSupport_ptr
OpenDDS::DCPS::TypeSupport::_duplicate (TypeSupport_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
OpenDDS::DCPS::TypeSupport::_tao_release (TypeSupport_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
OpenDDS::DCPS::TypeSupport::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:DDS/TypeSupport:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:OpenDDS/DCPS/TypeSupport:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* OpenDDS::DCPS::TypeSupport::_interface_repository_id (void) const
{
  return "IDL:OpenDDS/DCPS/TypeSupport:1.0";
}

::CORBA::Boolean
OpenDDS::DCPS::TypeSupport::marshal (TAO_OutputCDR & /* cdr */)
{
  return false;
}

