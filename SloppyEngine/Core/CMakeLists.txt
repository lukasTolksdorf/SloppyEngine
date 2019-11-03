add_library_without_mut(SloppyEngineCoreLib
        include/SloppyEngine/Core/SloppyEngine.hpp
        src/SloppyEngine.cc
        )

target_link_libraries_without_mut(SloppyEngineCoreLib
        SloppyEngingeUtilitiesLib
        peripheryInterfaceLib
        )