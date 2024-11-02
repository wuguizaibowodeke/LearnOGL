cmake_minimum_required (VERSION 3.31)
 
project (learnopengl_demo)

file(GLOB ASSETS "./assets")

file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(src)

add_executable(demo main.cpp glad.c )

target_link_libraries(demo opengl32 glfw3 Wrapper App Shader
                      Model Camera Light Renderer)