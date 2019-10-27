//
// Created by lukas on 16.10.19.
//

#include "SloppyEngine/SloppyEngine.hpp"

#include "SloppyEngine/Logger.hpp"

#include <iostream>

namespace Sloppy {

Application* Application::instance_ = nullptr;

void Application::run() {
  SLPY_CORE_TRACE("Application started");
}
Application::Application() {

  instance_ = this;
}

} // namespace Sloppy
