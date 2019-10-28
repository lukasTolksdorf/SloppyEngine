add_executable(UtSloppyEvents
        UtDispatcher.cc
        MockEventHandler.cc MockEventHandler.hpp)

target_link_libraries(UtSloppyEvents
        SloppyEngineEventsLib
        gtest gtest_main gmock)

set_property(TARGET UtSloppyEvents PROPERTY CXX_STANDARD 17)