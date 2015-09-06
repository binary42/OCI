/*
 * $Id: MessageTypes.h 5843 2012-10-09 17:42:24Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef RTPS_MESSAGETYPES_H
#define RTPS_MESSAGETYPES_H

#include "RtpsMessageTypesC.h"

namespace OpenDDS {
  namespace RTPS {

    // For messages we create, the "octetsToInlineQoS" value will be constant.
    const ACE_CDR::UShort DATA_OCTETS_TO_IQOS = 16;
    const ACE_CDR::UShort DATA_FRAG_OCTETS_TO_IQOS = 28;

    const ACE_CDR::UShort RTPSHDR_SZ = 20, // size of RTPS Message Header
      SMHDR_SZ = 4, // size of SubmessageHeader
      HEARTBEAT_SZ = 28, // size (octetsToNextHeader) of HeartBeatSubmessage
      INFO_DST_SZ = 12, // size (octetsToNextHeader) of InfoDestSubmessage
      INFO_TS_SZ = 8; // size of InfoTimestampSubmessage with FLAG_I == 0

    const OctetArray4
      PARTICIPANT_MESSAGE_DATA_KIND_UNKNOWN =
        { 0x00, 0x00, 0x00, 0x00 },
      PARTICIPANT_MESSAGE_DATA_KIND_AUTOMATIC_LIVELINESS_UPDATE =
        { 0x00, 0x00, 0x00, 0x01 },
      PARTICIPANT_MESSAGE_DATA_KIND_MANUAL_LIVELINESS_UPDATE =
        { 0x00, 0x00, 0x00, 0x02 };

  }
}

#endif /* RTPS_MESSAGETYPES_H */
