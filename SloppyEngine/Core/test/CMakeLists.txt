add_executable(UtSloppyCore
        MockLayer.hpp
        MockLayer.cc
        UtLayerStack.cc
        )

target_link_libraries(UtSloppyCore
        SloppyEngineCoreLib
        gtest gtest_main gmock)

set_property(TARGET UtSloppyCore PROPERTY CXX_STANDARD 17)