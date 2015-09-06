/*
 * $Id: UpdateProcessor_T.h 4381 2011-03-04 20:56:23Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef UPDATEPROCESSOR_T_H
#define UPDATEPROCESSOR_T_H

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace DDS {

struct SampleInfo;

} // namespace DDS

namespace OpenDDS {
namespace Federator {

/**
 * @class UpdateProcessor
 *
 * @brief Interface for managing update publications.
 *
 * This class provides interfaces to manage update data received from
 * federated repositories.
 */
template<class DataType>
class  UpdateProcessor {
public:
  /// Default constructor.
  UpdateProcessor();

  /// Virtual destructor
  virtual ~UpdateProcessor();

  //
  // Abstract interface to be implemented per application.
  //

  /// Entities are created.
  virtual void processCreate(
    const DataType*          sample,
    const DDS::SampleInfo* info) = 0;

  /// Entity Qos values are modified.
  virtual void processUpdateQos1(
    const DataType*          sample,
    const DDS::SampleInfo* info) = 0;

  /// Entity additional Qos values are modified.
  /// A default null implementation is provided.
  virtual void processUpdateQos2(
    const DataType*          sample,
    const DDS::SampleInfo* info);

  /// A default null implementation is provided.
  virtual void processUpdateFilterExpressionParams(
    const DataType*        sample,
    const DDS::SampleInfo* info);

  /// Entities are destroyed.
  virtual void processDelete(
    const DataType*          sample,
    const DDS::SampleInfo* info) = 0;

  //
  // Concrete implementation of common processing.
  //

  /// Update publication information with sample data.
  void processSample(
    const DataType*          sample,
    const DDS::SampleInfo* info);

};

} // namespace Federator
} // namespace OpenDDS

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "UpdateProcessor_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma message ("UpdateProcessor_T.cpp template inst")
#pragma implementation ("UpdateProcessor_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif  /* UPDATEPROCESSOR_T_H */
