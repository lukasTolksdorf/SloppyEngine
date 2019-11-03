
#include "Platform/Window.hpp"

namespace Sloppy::Platform {

WindowImpl::WindowImpl(const WindowProps &props)
    : data_{props.title, props.width, props.height, nullptr} {

  int success = glfwInit();

  window_ = glfwCreateWindow(static_cast<int>(data_.width), static_cast<int>(data_.height), data_.title.c_str(), nullptr, nullptr);
  //intentionally left empty
}

void WindowImpl::onUpdate() {}

unsigned int WindowImpl::getWidth() const { return 0; }
unsigned int WindowImpl::getHeight() const { return 0; }

void WindowImpl::setEventCallback(
    const std::function<void(Events::Event &)> &callback) {

  data_.eventCallback_ = callback;
}

void *WindowImpl::getNativeWindow() const { return nullptr; }

Window *Window::create(const WindowProps &props) {
  return new WindowImpl(props);
}
} // namespace Sloppy::Platform
