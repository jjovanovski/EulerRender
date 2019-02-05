add_executable(Sandbox main.cpp)

target_include_directories(Sandbox PRIVATE
    ../EulerRender/src
)

target_link_libraries(Sandbox EulerRender)

set_target_properties(Sandbox
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "../binaries/"
    LIBRARY_OUTPUT_DIRECTORY "../binaries/"
    RUNTIME_OUTPUT_DIRECTORY "../binaries/"
)