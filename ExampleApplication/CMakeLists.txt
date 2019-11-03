add_executable(ExampleApp src/exampleApp.cc)

target_link_libraries(ExampleApp
        SloppyEngineCoreLib
        peripheryLib
        )

set_property(TARGET ExampleApp PROPERTY CXX_STANDARD 17)
set_target_properties(ExampleApp PROPERTIES LINKER_LANGUAGE CXX)