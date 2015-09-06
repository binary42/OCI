/*
 * $Id: Replayer.h 5871 2012-11-08 22:29:43Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */


#ifndef OPENDDS_DCPS_REPLAYER_H
#define OPENDDS_DCPS_REPLAYER_H

#include <vector>
#include "dds/DCPS/RcObject_T.h"
#include "dds/DCPS/RcHandle_T.h"
#include "dds/DCPS/RawDataSample.h"

namespace OpenDDS {
namespace DCPS {

class Replayer;
typedef RcHandle<Replayer> Replayer_rch;

/**
 * @class ReplayerListener
 *
 * @brief Listener for handling callbacks from the Replayer
 *
 * This class is for handling callbacks from the Replayer object.
 */
class OpenDDS_Dcps_Export ReplayerListener : public RcObject<ACE_SYNCH_MUTEX> {
public:
  ~ReplayerListener();
  /**
   *  Callback for when the Replayer is associated with a DataReader.
   *  @param replayer Replayer that received the association
   */
  virtual void on_replayer_matched(Replayer*                               replayer,
                                   const ::DDS::PublicationMatchedStatus & status );
};

typedef RcHandle<ReplayerListener> ReplayerListener_rch;

typedef std::vector<RawDataSample> RawDataSampleList;
/**
 * @class Replayer
 *
 * @brief Send raw data samples in the system
 *
 * This class is for sending raw sample data.  Combined with data saved from
 * a recorder, this allows the data to be replayed to DataReaders.
 */
class OpenDDS_Dcps_Export Replayer : public RcObject<ACE_SYNCH_MUTEX> {
public:
  virtual ~Replayer();
  /**
   * Send the sample to all associated DataReaders.
   *
   * @note Only samples of type SAMPLE_DATA should be sent.
   */
  virtual DDS::ReturnCode_t write (const RawDataSample& sample )=0;

  /**
   * Send the sample to the specified DataReader.
   *
   * @note Only samples of type SAMPLE_DATA should be sent.
   */
  virtual DDS::ReturnCode_t write_to_reader (DDS::InstanceHandle_t subscription,                                                       // from PublicationMatchedStatus
                                             const RawDataSample&  sample )=0;

  /**
   * Send the samples to the specified DataReader.
   *
   * @note Only samples of type SAMPLE_DATA should be sent.
   */
  virtual DDS::ReturnCode_t write_to_reader (DDS::InstanceHandle_t    subscription,                                                    // from PublicationMatchedStatus
                                             const RawDataSampleList& samples )=0;

  /**
   * Set the Quality of Service settings for the Replayer.
   *
   */
  virtual DDS::ReturnCode_t set_qos (const ::DDS::PublisherQos & publisher_qos,
                                     const DDS::DataWriterQos &  datawriter_qos)=0;

  /**
   * Get the Quality of Service settings for the Replayer.
   *
   */
  virtual DDS::ReturnCode_t get_qos (DDS::PublisherQos &  publisher_qos,
                                     DDS::DataWriterQos & datawriter_qos)=0;

  /**
   * Change the listener for this Replayer.
   *
   */
  virtual DDS::ReturnCode_t set_listener (const ReplayerListener_rch & a_listener,
                                          DDS::StatusMask              mask = DEFAULT_STATUS_MASK)=0;

  /**
   * Get the listener for this Replayer.
   *
   */
  virtual ReplayerListener_rch get_listener ()=0;
};

} // namespace DCPS
} // namespace

#endif /* end of include guard: OPENDDS_DCPS_REPLAYER_H */
