#ifndef SLOPPYENGINE_PLATFORM_WINDOWINTERFACE_HPP_
#define SLOPPYENGINE_PLATFORM_WINDOWINTERFACE_HPP_

#include "SloppyEngine/Events/Event.hpp"

#include <functional>
#include <string>

namespace Sloppy::Platform {

struct WindowProps {
  std::string title;
  unsigned int width;
  unsigned int height;

  explicit WindowProps(const std::string &title_p = "Sloppy Engine Application",
              unsigned int width_p = 1280, unsigned int height_p = 720)
      : title(title_p), width(width_p), height(height_p) {
    // intentionally left empty
  }
};

class Window {
public:

  virtual ~Window() = default;

  virtual void onUpdate() = 0;

  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;

  virtual void setEventCallback(
      const std::function<void(Sloppy::Events::Event &)> &callback) = 0;

  virtual void *getNativeWindow() const = 0;

  static Window *create(const WindowProps &props = WindowProps());
};
} // namespace Sloppy::Platform
#endif // SLOPPYENGINE_PLATFORM_WINDOWINTERFACE_HPP_
