add_library_without_mut(SloppyEngineLib
        include/SloppyEngine/Logger.hpp
        include/SloppyEngine/SloppyEngine.hpp
        src/Logger.cc
        src/SloppyEngine.cc
)

target_link_libraries_without_mut(SloppyEngineLib)