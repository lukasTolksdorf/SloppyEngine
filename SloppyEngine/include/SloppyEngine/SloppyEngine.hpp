#ifndef SLOPPYENGINE_SLOPPYENGINE_HPP_
#define SLOPPYENGINE_SLOPPYENGINE_HPP_

#include "Logger.hpp"

namespace Sloppy {

class Application {
public:
  Application();
  virtual ~Application() = default;

  void run();
private:
  bool running_;

  static Application* instance_;
};

// Shall be defined by client
Application* CreateApplication();

} // namespace Sloppy

#endif // SLOPPYENGINE_SLOPPYENGINE_HPP_
