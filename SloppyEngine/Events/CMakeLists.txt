add_library_without_mut(SloppyEngineEventsLib
        include/SloppyEngine/Events/Dispatcher.hpp
        src/Dispatcher.cc
        include/SloppyEngine/Events/Event.hpp
        include/SloppyEngine/Events/WindowEvents.hpp
        )

target_link_libraries_without_mut(SloppyEngineEventsLib)


if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTS)
    add_subdirectory(test)
endif ()