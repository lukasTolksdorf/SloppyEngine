
#include "Platform/Window.hpp"

#include "SloppyEngine/Events/WindowEvents.hpp"
#include "SloppyEngine/Utilities/Logger.hpp"

#include <GLFW/glfw3.h>

namespace Sloppy::Platform {

WindowImpl::WindowImpl(const WindowProps &props)
    : data_{props.title, props.width, props.height, nullptr}, window_(nullptr) {

  int success = glfwInit();
  SLPY_CORE_TRACE("GLFW Windows init executed with {}", success);

  window_ = glfwCreateWindow(static_cast<int>(data_.width), static_cast<int>(data_.height), data_.title.c_str(), nullptr, nullptr);
  context_ = std::make_unique<OpenGLContext>(window_);

  glfwSetWindowUserPointer(window_, &data_);

  glfwSetWindowSizeCallback(window_, [](GLFWwindow* window, int width, int height){
    WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    data.width = static_cast<unsigned int >(width);
    data.height = static_cast<unsigned int>(height);

    Events::WindowResizeEvent event(data.width, data.height);
    data.eventCallback(event);
  });

  glfwSetWindowCloseCallback(window_, [](GLFWwindow* window){
    WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

    Events::WindowCloseEvent event{};
    data.eventCallback(event);
  });
}
WindowImpl::~WindowImpl() {
  glfwDestroyWindow(window_);
  SLPY_CORE_INFO("Detroyed Windows");
  glfwTerminate();
  SLPY_CORE_INFO("Terminated GLFW");

}

void WindowImpl::onUpdate() {
  glfwPollEvents();
  context_->SwapBuffers();
}

unsigned int WindowImpl::getWidth() const { return 0; }
unsigned int WindowImpl::getHeight() const { return 0; }

void WindowImpl::setEventCallback(
    const std::function<void(Events::Event &)> &callback) {

  data_.eventCallback = callback;
}

void *WindowImpl::getNativeWindow() const { return nullptr; }

Window *Window::create(const WindowProps &props) {
  return new WindowImpl(props);
}
} // namespace Sloppy::Platform
