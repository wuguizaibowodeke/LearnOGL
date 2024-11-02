file(GLOB_RECURSE RENDERER ./ *.cpp )

add_library(Renderer STATIC ${RENDERER})

target_include_directories(Renderer PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_include_directories(Renderer PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_include_directories(Renderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Renderer PUBLIC Shader)