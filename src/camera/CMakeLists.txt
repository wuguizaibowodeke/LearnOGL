file(GLOB_RECURSE CAMERA ./ *.cpp)

add_library(Camera ${CAMERA})

target_include_directories(Camera PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(Camera PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})