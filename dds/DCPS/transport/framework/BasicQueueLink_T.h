/*
 * $Id: BasicQueueLink_T.h 4223 2011-02-04 23:01:46Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_BASICQUEUELINK_T_H
#define OPENDDS_DCPS_BASICQUEUELINK_T_H

namespace OpenDDS {
namespace DCPS {

template <typename T>
class BasicQueueLink {
public:

  BasicQueueLink()
  : elem_(0),
      next_(0) {
  }

  BasicQueueLink(T* value)
  : elem_(value),
      next_(0) {
  }

  /// Accessor for elem_ data memeber.
  T* elem() {
    return this->elem_;
  }

  /// Mutator for elem_ data memeber.
  void elem(T* value) {
    this->elem_ = value;
  }

  /// Accessor for reference to the elem_ data memeber.
  T*& elem_ref() {
    return this->elem_;
  }

  /// Accessor for next_ data member.
  BasicQueueLink<T>* next() {
    return this->next_;
  }

  /// Mutator for next_ data member.
  void next(BasicQueueLink<T>* value) {
    this->next_ = value;
  }

  /// Changes state of this object to match the state of the
  /// object following (default) construction.
  void reset() {
    this->elem_ = 0;
    this->next_ = 0;
  }

private:

  /// The "payload" of the link -- the actual pointer that is
  /// being "wrapped" inside this link.
  T* elem_;

  /// The next link, or NULL (0) if this is the last link.
  BasicQueueLink<T>* next_;
};

} // namespace DCPS
} // namespace OpenDDS

#endif  /* OPENDDS_DCPS_BASICQUEUELINK_T_H */
