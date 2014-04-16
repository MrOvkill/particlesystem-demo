cmake_minimum_required(VERSION 2.6)

project(Grant)

include_directories(include)

file(GLOB Source
    "src/*.cxx"
)

add_subdirectory(libs/glfw3)
include_directories(libs/glfw3/include)

add_executable(Grant ${Source})

target_link_libraries(Grant glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
