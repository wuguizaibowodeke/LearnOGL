file(GLOB_RECURSE LIGHT ./ *.cpp *.h)

add_library(Light STATIC ${LIGHT})

target_include_directories(Light PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(Light PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})