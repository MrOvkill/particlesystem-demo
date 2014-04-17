cmake_minimum_required(VERSION 2.6)

project(GLEW)

include_directories(include)

add_definitions(-DGLEW_NO_GLU)

file(GLOB Source
    "src/*.c"
)

add_library(GLEW_LIB STATIC ${Source})


