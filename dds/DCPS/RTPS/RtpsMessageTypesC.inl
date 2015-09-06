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
// be/be_visitor_union/union_ci.cpp:39

// *************************************************************
// Inline operations for union OpenDDS::RTPS::Submessage
// *************************************************************

// TAO_IDL - Generated from
// be/be_visitor_union/discriminant_ci.cpp:58

// Accessor to set the discriminant.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::_d (OpenDDS::RTPS::SubmessageKind discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
OpenDDS::RTPS::SubmessageKind
OpenDDS::RTPS::Submessage::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::pad_sm (const OpenDDS::RTPS::PadSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::PAD;
  this->u_.pad_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::PadSubmessage &
OpenDDS::RTPS::Submessage::pad_sm (void) const
{
  return this->u_.pad_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::PadSubmessage &
OpenDDS::RTPS::Submessage::pad_sm (void)
{
  return this->u_.pad_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::acknack_sm (const OpenDDS::RTPS::AckNackSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::ACKNACK;
  ACE_NEW (
      this->u_.acknack_sm_,
      OpenDDS::RTPS::AckNackSubmessage (val)
    );
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::AckNackSubmessage &
OpenDDS::RTPS::Submessage::acknack_sm (void) const
{
  return *this->u_.acknack_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::AckNackSubmessage &
OpenDDS::RTPS::Submessage::acknack_sm (void)
{
  return *this->u_.acknack_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::heartbeat_sm (const OpenDDS::RTPS::HeartBeatSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::HEARTBEAT;
  this->u_.heartbeat_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::HeartBeatSubmessage &
OpenDDS::RTPS::Submessage::heartbeat_sm (void) const
{
  return this->u_.heartbeat_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::HeartBeatSubmessage &
OpenDDS::RTPS::Submessage::heartbeat_sm (void)
{
  return this->u_.heartbeat_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::gap_sm (const OpenDDS::RTPS::GapSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::GAP;
  ACE_NEW (
      this->u_.gap_sm_,
      OpenDDS::RTPS::GapSubmessage (val)
    );
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::GapSubmessage &
OpenDDS::RTPS::Submessage::gap_sm (void) const
{
  return *this->u_.gap_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::GapSubmessage &
OpenDDS::RTPS::Submessage::gap_sm (void)
{
  return *this->u_.gap_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::info_ts_sm (const OpenDDS::RTPS::InfoTimestampSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::INFO_TS;
  this->u_.info_ts_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::InfoTimestampSubmessage &
OpenDDS::RTPS::Submessage::info_ts_sm (void) const
{
  return this->u_.info_ts_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::InfoTimestampSubmessage &
OpenDDS::RTPS::Submessage::info_ts_sm (void)
{
  return this->u_.info_ts_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::info_src_sm (const OpenDDS::RTPS::InfoSourceSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::INFO_SRC;
  this->u_.info_src_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::InfoSourceSubmessage &
OpenDDS::RTPS::Submessage::info_src_sm (void) const
{
  return this->u_.info_src_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::InfoSourceSubmessage &
OpenDDS::RTPS::Submessage::info_src_sm (void)
{
  return this->u_.info_src_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::info_reply_ipv4_sm (const OpenDDS::RTPS::InfoReplyIp4Submessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::INFO_REPLY_IP4;
  this->u_.info_reply_ipv4_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::InfoReplyIp4Submessage &
OpenDDS::RTPS::Submessage::info_reply_ipv4_sm (void) const
{
  return this->u_.info_reply_ipv4_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::InfoReplyIp4Submessage &
OpenDDS::RTPS::Submessage::info_reply_ipv4_sm (void)
{
  return this->u_.info_reply_ipv4_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::info_dst_sm (const OpenDDS::RTPS::InfoDestinationSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::INFO_DST;
  this->u_.info_dst_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::InfoDestinationSubmessage &
OpenDDS::RTPS::Submessage::info_dst_sm (void) const
{
  return this->u_.info_dst_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::InfoDestinationSubmessage &
OpenDDS::RTPS::Submessage::info_dst_sm (void)
{
  return this->u_.info_dst_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::info_reply_sm (const OpenDDS::RTPS::InfoReplySubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::INFO_REPLY;
  ACE_NEW (
      this->u_.info_reply_sm_,
      OpenDDS::RTPS::InfoReplySubmessage (val)
    );
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::InfoReplySubmessage &
OpenDDS::RTPS::Submessage::info_reply_sm (void) const
{
  return *this->u_.info_reply_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::InfoReplySubmessage &
OpenDDS::RTPS::Submessage::info_reply_sm (void)
{
  return *this->u_.info_reply_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::nack_frag_sm (const OpenDDS::RTPS::NackFragSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::NACK_FRAG;
  ACE_NEW (
      this->u_.nack_frag_sm_,
      OpenDDS::RTPS::NackFragSubmessage (val)
    );
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::NackFragSubmessage &
OpenDDS::RTPS::Submessage::nack_frag_sm (void) const
{
  return *this->u_.nack_frag_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::NackFragSubmessage &
OpenDDS::RTPS::Submessage::nack_frag_sm (void)
{
  return *this->u_.nack_frag_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::hb_frag_sm (const OpenDDS::RTPS::HeartBeatFragSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::HEARTBEAT_FRAG;
  this->u_.hb_frag_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::HeartBeatFragSubmessage &
OpenDDS::RTPS::Submessage::hb_frag_sm (void) const
{
  return this->u_.hb_frag_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::HeartBeatFragSubmessage &
OpenDDS::RTPS::Submessage::hb_frag_sm (void)
{
  return this->u_.hb_frag_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::data_sm (const OpenDDS::RTPS::DataSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::DATA;
  ACE_NEW (
      this->u_.data_sm_,
      OpenDDS::RTPS::DataSubmessage (val)
    );
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::DataSubmessage &
OpenDDS::RTPS::Submessage::data_sm (void) const
{
  return *this->u_.data_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::DataSubmessage &
OpenDDS::RTPS::Submessage::data_sm (void)
{
  return *this->u_.data_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::data_frag_sm (const OpenDDS::RTPS::DataFragSubmessage &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::DATA_FRAG;
  ACE_NEW (
      this->u_.data_frag_sm_,
      OpenDDS::RTPS::DataFragSubmessage (val)
    );
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::DataFragSubmessage &
OpenDDS::RTPS::Submessage::data_frag_sm (void) const
{
  return *this->u_.data_frag_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::DataFragSubmessage &
OpenDDS::RTPS::Submessage::data_frag_sm (void)
{
  return *this->u_.data_frag_sm_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1068

/// Accessor to set the member.
ACE_INLINE
void
OpenDDS::RTPS::Submessage::unknown_sm (const OpenDDS::RTPS::SubmessageHeader &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = OpenDDS::RTPS::RESERVED_0;
  this->u_.unknown_sm_ = val;
}

// Readonly get method.
ACE_INLINE
const OpenDDS::RTPS::SubmessageHeader &
OpenDDS::RTPS::Submessage::unknown_sm (void) const
{
  return this->u_.unknown_sm_;
}

// Read/write get method.
ACE_INLINE
OpenDDS::RTPS::SubmessageHeader &
OpenDDS::RTPS::Submessage::unknown_sm (void)
{
  return this->u_.unknown_sm_;
}

