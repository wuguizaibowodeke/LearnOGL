add_library(App STATIC app.cpp)

target_include_directories(App PUBLIC ${CMAKE_SOURCE_DIR}/include)
