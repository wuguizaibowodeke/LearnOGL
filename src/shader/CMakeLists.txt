file(GLOB_RECURSE Shader ./ *.cpp )

add_library(Shader STATIC ${Shader})

target_include_directories(Shader PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(Shader PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})