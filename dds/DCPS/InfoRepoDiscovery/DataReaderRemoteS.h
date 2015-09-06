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
// be/be_codegen.cpp:461

#ifndef _TAO_IDL_DATAREADERREMOTES_7KQCWG_H_
#define _TAO_IDL_DATAREADERREMOTES_7KQCWG_H_

#include /**/ "ace/pre.h"

#include "DataReaderRemoteC.h"
#include "dds/DdsDcpsInfoUtilsS.h"
#include "dds/DdsDcpsInfrastructureS.h"
#include "dds/DdsDcpsSubscriptionS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:147

#if !defined (_OPENDDS_DCPS_DATAREADERREMOTE__SARG_TRAITS_)
#define _OPENDDS_DCPS_DATAREADERREMOTE__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::OpenDDS::DCPS::DataReaderRemote>
    : public
        Object_SArg_Traits_T<
            ::OpenDDS::DCPS::DataReaderRemote_ptr,
            ::OpenDDS::DCPS::DataReaderRemote_var,
            ::OpenDDS::DCPS::DataReaderRemote_out,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_sh.cpp:38

namespace POA_OpenDDS
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_module/module_sh.cpp:38

  namespace DCPS
  {
    

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_sh.cpp:76

    class DataReaderRemote;
    typedef DataReaderRemote *DataReaderRemote_ptr;

    class OpenDDS_InfoRepoDiscovery_Export DataReaderRemote
      : public virtual PortableServer::ServantBase
    {
    protected:
      DataReaderRemote (void);
    
    public:
      /// Useful for template programming.
      typedef ::OpenDDS::DCPS::DataReaderRemote _stub_type;
      typedef ::OpenDDS::DCPS::DataReaderRemote_ptr _stub_ptr_type;
      typedef ::OpenDDS::DCPS::DataReaderRemote_var _stub_var_type;

      DataReaderRemote (const DataReaderRemote& rhs);
      virtual ~DataReaderRemote (void);

      virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

      virtual void _dispatch (
          TAO_ServerRequest & req,
          TAO::Portable_Server::Servant_Upcall *servant_upcall);
      
      ::OpenDDS::DCPS::DataReaderRemote *_this (void);
      
      virtual const char* _interface_repository_id (void) const;

      // TAO_IDL - Generated from
      // be/be_visitor_operation/operation_sh.cpp:39

      virtual void add_association (
        const ::OpenDDS::DCPS::RepoId & yourId,
        const ::OpenDDS::DCPS::WriterAssociation & writer,
        ::CORBA::Boolean active) = 0;

      static void add_association_skel (
          TAO_ServerRequest &server_request,
          TAO::Portable_Server::Servant_Upcall *servant_upcall,
          TAO_ServantBase *servant);

      // TAO_IDL - Generated from
      // be/be_visitor_operation/operation_sh.cpp:39

      virtual void association_complete (
        const ::OpenDDS::DCPS::RepoId & remote_id) = 0;

      static void association_complete_skel (
          TAO_ServerRequest &server_request,
          TAO::Portable_Server::Servant_Upcall *servant_upcall,
          TAO_ServantBase *servant);

      // TAO_IDL - Generated from
      // be/be_visitor_operation/operation_sh.cpp:39

      virtual void remove_associations (
        const ::OpenDDS::DCPS::WriterIdSeq & writers,
        ::CORBA::Boolean notify_lost) = 0;

      static void remove_associations_skel (
          TAO_ServerRequest &server_request,
          TAO::Portable_Server::Servant_Upcall *servant_upcall,
          TAO_ServantBase *servant);

      // TAO_IDL - Generated from
      // be/be_visitor_operation/operation_sh.cpp:39

      virtual void update_incompatible_qos (
        const ::OpenDDS::DCPS::IncompatibleQosStatus & status) = 0;

      static void update_incompatible_qos_skel (
          TAO_ServerRequest &server_request,
          TAO::Portable_Server::Servant_Upcall *servant_upcall,
          TAO_ServantBase *servant);
    };
  
  // TAO_IDL - Generated from
  // be/be_visitor_module/module_sh.cpp:69

  } // module OpenDDS::DCPS

// TAO_IDL - Generated from
// be/be_visitor_module/module_sh.cpp:69

} // module OpenDDS

#include /**/ "ace/post.h"

#endif /* ifndef */

