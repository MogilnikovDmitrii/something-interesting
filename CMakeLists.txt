cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(PROJECT_NAME MyGameEngine)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_X11 ON CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)


