#ifndef SLOPPYENGINE_EVENTS_DISPATCHER_HPP_
#define SLOPPYENGINE_EVENTS_DISPATCHER_HPP_

#include "Event.hpp"

namespace Sloppy::Events {

class Dispatcher {
public:
  explicit Dispatcher(Event &event);

  template <typename EventType, typename CallbackType>
  bool Dispatch(const CallbackType &callback) {
    if (event_.GetEventType() == EventType::GetStaticType()) {
      event_.handled = callback(static_cast<CallbackType &>(event_));
      return true;
    }
    return false;
  }

private:
  Event &event_;
};

} // namespace Sloppy::Events

#endif // SLOPPYENGINE_EVENTS_DISPATCHER_HPP_
