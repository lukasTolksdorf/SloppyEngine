#include "SloppyEngine/Core/SloppyEngine.hpp"

#include "SloppyEngine/Core/Logger.hpp"

namespace Sloppy {

Application *Application::instance_ = nullptr;

void Application::run() {
  SLPY_CORE_TRACE("Application started");

  window_ = std::unique_ptr<Platform::Window>(Platform::Window::create());
  window_->setEventCallback([this](Events::Event &e) { this->onEvent(e); });

}

Application::Application() { instance_ = this; }

void Application::onEvent(Events::Event &e) {
  SLPY_INFO("Event triggered!", e.toString());
}

} // namespace Sloppy
