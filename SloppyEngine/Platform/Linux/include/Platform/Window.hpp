#ifndef SLOPPYENGINE_LINUX_WINDOW_HPP_
#define SLOPPYENGINE_LINUX_WINDOW_HPP_

#include "Platform/WindowInterface.hpp"

#include "GLFW/glfw3.h"

namespace Sloppy::Platform {
class WindowImpl : public Window {

public:
  explicit WindowImpl(const WindowProps& props );
  ~WindowImpl() override = default;

  void onUpdate() override;

  unsigned int getWidth() const override;
  unsigned int getHeight() const override;

  void setEventCallback(
      const std::function<void(Sloppy::Events::Event &)> &callback) override;

  void *getNativeWindow() const override;

private:
  GLFWwindow* window_;


  struct WindowData {
  std::string title;
  unsigned int width;
  unsigned int height;
  std::function<void(Sloppy::Events::Event &)> eventCallback_;
  };

  WindowData data_;

};

} // namespace Sloppy::Platform

#endif // SLOPPYENGINE_LINUX_WINDOW_HPP_
