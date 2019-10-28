#ifndef SLOPPYENGINE_EVENTS_WINDOWEVENTS_HPP_
#define SLOPPYENGINE_EVENTS_WINDOWEVENTS_HPP_

#include "Event.hpp"

#include <sstream>
#include <string>

namespace Sloppy::Events {

class WindowCloseEvent : public Event {
public:
  GENERATE_EVENT_TYPE_INFO(WindowClose);
};

class WindowResizeEvent : public Event {
public:
  WindowResizeEvent(unsigned int width, unsigned int height)
      : width_(width), height_(height) {
    // intentionally left empty
  }

  GENERATE_EVENT_TYPE_INFO(WindowResize);

  std::string toString() const override {
    std::stringstream stream;
    stream << getName() << " with height " << height_ << " and width "
           << width_;
    return stream.str();
  }

private:
  unsigned int width_;
  unsigned int height_;
};
} // namespace Sloppy::Events
#endif // SLOPPYENGINE_EVENTS_WINDOWEVENTS_HPP_
