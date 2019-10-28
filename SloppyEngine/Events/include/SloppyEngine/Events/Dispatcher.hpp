#ifndef SLOPPYENGINE_EVENTS_DISPATCHER_HPP_
#define SLOPPYENGINE_EVENTS_DISPATCHER_HPP_

#include "Event.hpp"

namespace Sloppy::Events {

class Dispatcher {
public:
  explicit Dispatcher(Event &event);

  template <typename EventType, typename HandlerType>
  bool dispatch(const HandlerType &fcn) {
    if (event_.getEventType() == EventType::getStaticType()) {
      event_.handled = fcn(static_cast<EventType &>(event_));
      return true;
    }
    return false;
  }

private:
  Event &event_;
};

} // namespace Sloppy::Events

#endif // SLOPPYENGINE_EVENTS_DISPATCHER_HPP_
