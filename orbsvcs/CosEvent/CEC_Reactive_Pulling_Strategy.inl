// -*- C++ -*-
//
// $Id: CEC_Reactive_Pulling_Strategy.inl 2388 2014-10-20 17:02:41Z mesnierp $

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
TAO_CEC_Pull_Event::TAO_CEC_Pull_Event (TAO_CEC_ConsumerAdmin *consumer_admin,
                                        TAO_CEC_SupplierControl *)
  :  consumer_admin_ (consumer_admin)
{
}

TAO_END_VERSIONED_NAMESPACE_DECL
