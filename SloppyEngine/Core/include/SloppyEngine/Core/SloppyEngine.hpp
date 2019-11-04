#ifndef SLOPPYENGINE_SLOPPYENGINE_HPP_
#define SLOPPYENGINE_SLOPPYENGINE_HPP_

#include "../../../../Utilities/include/SloppyEngine/Utilities/Logger.hpp"

#include "Platform/WindowInterface.hpp"

#include <SloppyEngine/Events/WindowEvents.hpp>
#include <memory>

namespace Sloppy {

class Application {
public:
  Application();
  virtual ~Application() = default;

  void run();
  void onEvent(Events::Event& e);
private:
  bool OnWindowClose(Events::WindowCloseEvent& e);
  bool OnWindowResize(Events::WindowResizeEvent& e);
  std::unique_ptr<Platform::Window> window_;
  bool running_;

  static Application* instance_;
};

// Shall be defined by client
extern Application* CreateApplication();

} // namespace Sloppy

#endif // SLOPPYENGINE_SLOPPYENGINE_HPP_
