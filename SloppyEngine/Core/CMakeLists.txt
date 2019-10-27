add_library_without_mut(SloppyEngineCoreLib
        include/SloppyEngine/Core/Logger.hpp
        include/SloppyEngine/Core/SloppyEngine.hpp
        src/Logger.cc
        src/SloppyEngine.cc
)

target_link_libraries_without_mut(SloppyEngineCoreLib
        spdlog)