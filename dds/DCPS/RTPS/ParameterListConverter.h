/*
 * $Id: ParameterListConverter.h 5266 2012-01-21 04:36:48Z mitza $
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef PARAMETER_LIST_CONVERTER_H
#define PARAMETER_LIST_CONVERTER_H

#include "dds/DCPS/RTPS/rtps_export.h"
#include "dds/DCPS/RTPS/RtpsMessageTypesC.h"

namespace OpenDDS { namespace RTPS {

namespace ParameterListConverter {
  OpenDDS_Rtps_Export
  int to_param_list(const SPDPdiscoveredParticipantData& participant_data,
                    ParameterList& param_list);
  OpenDDS_Rtps_Export
  int to_param_list(const DiscoveredWriterData& writer_data,
                    ParameterList& param_list);
  OpenDDS_Rtps_Export
  int to_param_list(const DiscoveredReaderData& writer_data,
                    ParameterList& param_list);
  OpenDDS_Rtps_Export
  int from_param_list(const ParameterList& param_list,
                      SPDPdiscoveredParticipantData& participant_data);
  OpenDDS_Rtps_Export
  int from_param_list(const ParameterList& param_list,
                      DiscoveredWriterData& writer_data);
  OpenDDS_Rtps_Export
  int from_param_list(const ParameterList& param_list,
                      DiscoveredReaderData& writer_data);
}
} }

#endif
