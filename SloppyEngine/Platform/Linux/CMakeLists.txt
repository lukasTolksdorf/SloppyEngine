add_library_without_mut(peripheryLib
        include/Platform/Window.hpp
        src/Window.cc
        )

target_link_libraries_without_mut(peripheryLib
        peripheryInterfaceLib
        glfw
        SloppyEngingeUtilitiesLib
        )