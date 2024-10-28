cmake_minimum_required (VERSION 3.31)
 
project (learnopengl_01)

file(GLOB ASSETS "./assets")

file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(src)

add_executable(opengl01 main.cpp glad.c )

target_link_libraries(opengl01 App glfw3 SHADER opengl32 Camera)