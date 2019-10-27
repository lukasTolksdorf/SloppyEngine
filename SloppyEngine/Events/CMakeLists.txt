add_library_without_mut(SloppyEngineEventsLib
        include/SloppyEngine/Events/Dispatcher.hpp
        src/Dispatcher.cc
        include/SloppyEngine/Events/Event.hpp
        )

target_link_libraries_without_mut(SloppyEngineEventsLib)