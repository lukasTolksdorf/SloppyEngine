add_library_without_mut(SloppyEngineCoreLib
        include/SloppyEngine/Core/Layer.hpp
        src/Layer.cc
        include/SloppyEngine/Core/SloppyEngine.hpp
        src/SloppyEngine.cc
        include/SloppyEngine/Core/LayerStack.hpp
        src/LayerStack.cc
        )

target_link_libraries_without_mut(SloppyEngineCoreLib
        SloppyEngingeUtilitiesLib
        peripheryInterfaceLib
        )

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTS)
    add_subdirectory(test)
endif ()