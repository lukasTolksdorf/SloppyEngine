add_library_without_mut(SloppyEngineOpenGLLib
        include/SloppyEngine/OpenGL/OpenGLContext.hpp
        src/OpenGLContext.cc
        )

target_link_libraries_without_mut(SloppyEngineOpenGLLib
        SloppyEngingeUtilitiesLib
        glfw
        glad)