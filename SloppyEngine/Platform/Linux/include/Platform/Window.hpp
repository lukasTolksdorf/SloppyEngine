#ifndef SLOPPYENGINE_LINUX_WINDOW_HPP_
#define SLOPPYENGINE_LINUX_WINDOW_HPP_

#include "Platform/WindowInterface.hpp"
#include <memory>

#include "SloppyEngine/OpenGL/OpenGLContext.hpp"

namespace Sloppy::Platform {
class WindowImpl : public Window {

public:
  explicit WindowImpl(const WindowProps &props);
  ~WindowImpl() override;

  void onUpdate() override;

  unsigned int getWidth() const override;
  unsigned int getHeight() const override;

  void setEventCallback(
      const std::function<void(Sloppy::Events::Event &)> &callback) override;

  void *getNativeWindow() const override;

private:
  struct WindowData {
    std::string title;
    unsigned int width;
    unsigned int height;
    std::function<void(Sloppy::Events::Event &)> eventCallback;
  };

  WindowData data_;

  GLFWwindow *window_;
  std::unique_ptr<OpenGLContext> context_;
};

} // namespace Sloppy::Platform

#endif // SLOPPYENGINE_LINUX_WINDOW_HPP_
