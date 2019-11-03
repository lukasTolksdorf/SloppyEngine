add_library_without_mut(SloppyEngingeUtilitiesLib
        include/SloppyEngine/Utilities/Logger.hpp
        src/Logger.cc
        )

target_link_libraries_without_mut(SloppyEngingeUtilitiesLib
        spdlog)