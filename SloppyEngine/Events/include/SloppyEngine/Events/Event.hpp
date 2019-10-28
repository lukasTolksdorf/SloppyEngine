#ifndef SLOPPYENGINE_EVENTS_EVENT_HPP_
#define SLOPPYENGINE_EVENTS_EVENT_HPP_

#include <string>

namespace Sloppy::Events {

// clang-format off
enum class EventType {
  None = 0,
  WindowClose, WindowResize,
  AppTick, AppUpdate, AppRenderer,
  KeyPressed, KeyRelease, KeyTyped,
  MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};
// clang-format on

class Event {
public:
  Event()
      : handled(false){
            // Intentionally left empty
        };

  virtual ~Event() = default;

  [[nodiscard]] virtual EventType getEventType() const = 0;
  [[nodiscard]] virtual std::string getName() const = 0;

  [[nodiscard]] virtual std::string toString() const { return getName();}

  bool handled;
};

//std::ostream &operator<<(std::ostream &os, const Event &e) {
//  return os << e.toString();
//}

// Helper macro for easy event definition
#define GENERATE_EVENT_TYPE_INFO(type)                                         \
  static EventType getStaticType() { return EventType::type; }                 \
  virtual EventType getEventType() const override { return getStaticType(); }  \
  virtual std::string getName() const override { return #type; }

} // namespace Sloppy::Events

#endif // SLOPPYENGINE_EVENTS_EVENT_HPP_
