cmake_minimum_required(VERSION 3.8.0)
project(EulerRender)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/assimp)
#add_subdirectory(thirdparty/stb)
add_subdirectory(thirdparty/glad)

add_subdirectory(EulerRender)
add_subdirectory(Sandbox)