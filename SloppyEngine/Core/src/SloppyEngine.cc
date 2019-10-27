#include "SloppyEngine/Core/SloppyEngine.hpp"

#include "SloppyEngine/Core/Logger.hpp"

namespace Sloppy {

Application* Application::instance_ = nullptr;

void Application::run() {
  SLPY_CORE_TRACE("Application started");
}
Application::Application() {

  instance_ = this;
}

} // namespace Sloppy
