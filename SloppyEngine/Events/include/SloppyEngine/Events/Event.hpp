#ifndef SLOPPYENGINE_EVENTS_EVENT_HPP_
#define SLOPPYENGINE_EVENTS_EVENT_HPP_

#include <string>
#include <string_view>

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
  Event():handled(false){
    //Intentionally left empty
  };

  virtual ~Event() = default;

  [[nodiscard]] virtual EventType GetEventType() const = 0;
  [[nodiscard]] virtual const std::string_view GetName() const = 0;
  [[nodiscard]] virtual std::string ToString() const = 0;

  bool handled;
};

std::ostream& operator<<(std::ostream& os, const Event& e){
  return os << e.GetName();
}

} // namespace Sloppy

#endif // SLOPPYENGINE_EVENTS_EVENT_HPP_
