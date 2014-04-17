cmake_minimum_required(VERSION 2.6)

project(ParticleSystemDemo)

include_directories(include)

file(GLOB Source
    "src/*.cxx"
)

add_subdirectory(libs/glew)
include_directories(libs/glew/include)

add_subdirectory(libs/glfw3)
include_directories(libs/glfw3/include)

add_executable(Simple ${Source} tests/Simple.cxx)

target_link_libraries(Simple GLEW_LIB glfw ${GLFW_LIBRARIES})
