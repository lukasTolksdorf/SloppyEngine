#include "SloppyEngine/Core/SloppyEngine.hpp"

#include "SloppyEngine/Utilities/Logger.hpp"

#include <SloppyEngine/Events/Dispatcher.hpp>
#include <SloppyEngine/Events/WindowEvents.hpp>

namespace Sloppy {

Application *Application::instance_ = nullptr;

Application::Application() {

  instance_ = this;
  SLPY_CORE_TRACE("Application started");

  window_ = std::unique_ptr<Platform::Window>(Platform::Window::create());
  window_->setEventCallback([this](Events::Event &e) { this->onEvent(e); });

  running_ = true;
}

void Application::run() {
  while (running_) {
    window_->onUpdate();
  }
}

void Application::onEvent(Events::Event &e) {
  Events::Dispatcher dispatcher(e);
  dispatcher.dispatch<Events::WindowCloseEvent>(
      [this](auto &event) { return OnWindowClose(event); });
  dispatcher.dispatch<Events::WindowResizeEvent>(
      [this](auto &event) { return OnWindowResize(event); });

  SLPY_INFO("Event triggered!", e.toString());
}
bool Application::OnWindowClose(Events::WindowCloseEvent &e) {
  SLPY_CORE_INFO("Window Close Event triggered");
  running_ = false;
  return true;
}
bool Application::OnWindowResize(Events::WindowResizeEvent &e) {
  SLPY_CORE_INFO("Window Resize Event");
  return true; }

} // namespace Sloppy
