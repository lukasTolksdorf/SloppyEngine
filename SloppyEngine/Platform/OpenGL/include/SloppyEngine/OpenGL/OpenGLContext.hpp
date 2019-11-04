#ifndef SLOPPYENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_HPP_
#define SLOPPYENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_HPP_

struct GLFWwindow;

namespace Sloppy::Platform {

class OpenGLContext {
public:
  explicit OpenGLContext(GLFWwindow* windowHandle);

  void SwapBuffers();

private:
  void init();
  GLFWwindow* windowHandle_;
};
}

#endif // SLOPPYENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_HPP_
