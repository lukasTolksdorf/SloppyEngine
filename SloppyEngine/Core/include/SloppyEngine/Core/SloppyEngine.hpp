#ifndef SLOPPYENGINE_SLOPPYENGINE_HPP_
#define SLOPPYENGINE_SLOPPYENGINE_HPP_

#include "Logger.hpp"

#include "Platform/WindowInterface.hpp"

#include <memory>

namespace Sloppy {

class Application {
public:
  Application();
  virtual ~Application() = default;

  void run();
  void onEvent(Events::Event& e);
private:
  std::unique_ptr<Platform::Window> window_;
  bool running_;

  static Application* instance_;
};

// Shall be defined by client
extern Application* CreateApplication();

} // namespace Sloppy

#endif // SLOPPYENGINE_SLOPPYENGINE_HPP_
