file(GLOB_RECURSE MODEL ./ *.cpp *.h)

add_library(Model STATIC ${MODEL})

target_include_directories(Model PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(Model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})