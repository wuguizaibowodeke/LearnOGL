file(GLOB_RECURSE SHADER ./ *.cpp )

add_library(SHADER STATIC ${SHADER})

target_include_directories(SHADER PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(SHADER PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})