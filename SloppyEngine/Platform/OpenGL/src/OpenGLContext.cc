#include "SloppyEngine/OpenGL/OpenGLContext.hpp"

#include "SloppyEngine/Utilities/Logger.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/gl.h>

namespace Sloppy::Platform {

OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
    : windowHandle_(windowHandle) {

  init();
}

void OpenGLContext::SwapBuffers() {
  glfwSwapBuffers(windowHandle_);
}
void OpenGLContext::init() {

  glfwMakeContextCurrent(windowHandle_);

  int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  SLPY_CORE_TRACE("loaded GLLoader with exit status: {}", status);

  SLPY_CORE_INFO("OpenGL info:");
  SLPY_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
  SLPY_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
  SLPY_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
}

} // namespace Sloppy::Platform
