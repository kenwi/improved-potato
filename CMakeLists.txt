cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graphics/Window.h Graphics/Window.cpp Graphics/Rendering/Renderer.cpp Graphics/Rendering/Renderer.h Graphics/Rendering/Object.h Graphics/Rendering/Primitives/Shape.cpp Graphics/Rendering/Primitives/Shape.h libs.h)
add_executable(untitled ${SOURCE_FILES})

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

include_directories(GLUS/src)

target_link_libraries(untitled glfw GL ${GLEW_LIBRARIES})
