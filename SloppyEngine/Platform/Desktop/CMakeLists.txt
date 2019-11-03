add_library_without_mut(peripheryInterfaceLib
        include/Platform/WindowInterface.hpp
        )

target_link_libraries_without_mut(peripheryInterfaceLib
        SloppyEngineEventsLib
        )