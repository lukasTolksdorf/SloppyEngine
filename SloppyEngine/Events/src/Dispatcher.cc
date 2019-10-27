#include "SloppyEngine/Events/Dispatcher.hpp"

namespace Sloppy::Events {

Dispatcher::Dispatcher(Event &event) : event_(event) {
  // intentionally left empty
}
} // namespace Sloppy::Events
