cmake_minimum_required(VERSION 3.5)
project(improved-potato)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${improved-potato_SOURCE_DIR}/bin)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# Source files
file(GLOB_RECURSE CPP_FILES ${improved-potato_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE H_FILES ${improved-potato_SOURCE_DIR}/*.h)

# Ignore
file(GLOB_RECURSE IGNORE_CPP_FILES ${improved-potato_SOURCE_DIR}/cmake-build-debug/*.cpp)
list(REMOVE_ITEM CPP_FILES ${IGNORE_CPP_FILES})

# Add GLUS variables
set(GLUS_INCLUDE_DIR ${improved-potato_SOURCE_DIR}/GLUS/src)
set(GLUS_LIBRARY_DIR ${improved-potato_SOURCE_DIR}/GLUS/build)

# Add include of files and library directory
include_directories(${GLUS_CPP_FILES} ${GLUS_H_FILES} ${GLUS_INCLUDE_DIR})
link_directories(${GLUS_LIBRARY_DIR})

add_executable(improved-potato ${CPP_FILES} ${H_FILES} ${GLUS_CPP_FILES} ${GLUS_H_FILES})
target_link_libraries(improved-potato glfw GL GLUS ${GLEW_LIBRARIES})

#file(GLOB_RECURSE GLUS_CPP_FILES ${improved-potato_SOURCE_DIR}/GLUS/src/*.cpp)
#file(GLOB_RECURSE GLUS_H_FILES ${improved-potato_SOURCE_DIR}/GLUS/src/*.h)

#set(GLUS_INCLUDE_DIR ${improved-potato_SOURCE_DIR}/GLUS/src)
#set(GLUS_LIBRARY_DIR ${improved-potato_SOURCE_DIR}/GLUS/build)

#add_library(GLUS ${GLUS_CPP_FILES} ${GLUS_H_FILES})

#link_directories(${GLUS_LIBRARY_DIR})

#set(GLUS_INCLUDE_DIR ${improved-potato_SOURCE_DIR}/GLUS/src)
#set(GLUS_LIBRARY_DIR ${improved-potato_SOURCE_DIR}/GLUS/build)























#set(SOURCE_FILES main.cpp Graphics/Window.h Graphics/Window.cpp Graphics/Rendering/Renderer.cpp Graphics/Rendering/Renderer.h Graphics/Rendering/Object.h Graphics/Rendering/Primitives/Shape.cpp Graphics/Rendering/Primitives/Shape.h libs.h Graphics/Shader/Shader.cpp Graphics/Shader/Shader.h Utils/Timer.cpp Utils/Timer.h)
#add_executable(improved-potato ${SOURCE_FILES})

#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#    include_directories(${GLEW_INCLUDE_DIRS})
#    link_libraries(${GLEW_LIBRARIES})
#endif()

#target_link_libraries(improved-potato glfw GL ${GLUS_LIBRARIES} ${GLEW_LIBRARIES})
#include_directories(${improved-potato_SOURCE_DIR}/GLUS/src)
#set(SOURCE_FILES main.cpp Graphics/Window.h Graphics/Window.cpp Graphics/Rendering/Renderer.cpp Graphics/Rendering/Renderer.h Graphics/Rendering/Object.h Graphics/Rendering/Primitives/Shape.cpp Graphics/Rendering/Primitives/Shape.h libs.h Graphics/Shader/Shader.cpp Graphics/Shader/Shader.h Utils/Timer.cpp Utils/Timer.h)
#add_executable(improved-potato ${SOURCE_FILES})

#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#    include_directories(${GLEW_INCLUDE_DIRS})
#    link_libraries(${GLEW_LIBRARIES})
#endif()

#set(GLUS_INCLUDE_DIR GLUS/src)
#set(GLUS_LIBRARY_DIR GLUS/build/CMakeFiles/GLUS.dir/)
#include_directories(${GLUS_INCLUDE_DIR})
#link_directories(${GLUS_LIBRARY_DIR})

#find_package(GLUS REQUIRED)
#if(GLUS_FOUND)
#    include_directories(${GLUS_INCLUDE_DIR})
#    link_directories(${GLUS_LIBRARY_DIR})
#endif()

#target_link_libraries(improved-potato glfw GL GLUS ${H_FILES} ${CPP_FILES} ${GLEW_LIBRARIES})


#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${improved-potato_SOURCE_DIR})
#set(CMAKE_MODULE_PATH ../GLUS/CMakeFiles/GLUS.dir/src)
#set(GLUS_INCLUDE_DIR ../GLUS/src)
#set(GLUS_LIBRARY_DIR ../GLUS/CMakeFiles/GLUS.dir/src)
#find_library(GLUS REQUIRED)
#if(GLUS_FOUND)
#    include_directories(${GLUS_INCLUDE_DIR})
#    link_directories(${GLUS_LIBRARY_DIR})
#endif()
#set(GLUS_INCLUDE_DIR ../GLUS/src)
#include_directories(${GLUS_INCLUDE_DIR})
#set(GLUS_LIBRARY_DIR ../GLUS/src)
#link_directories(${GLUS_LIBRARY_DIR})
#if(GLUS_FOUND)
    #include_directories(${GLUS_INCLUDE_DIR})
    #link_directories(../GLUS/src)
#endif()
#file(GLOB_RECURSE H_FILES ${improved-potato_SOURCE_DIR}/src/*.h)
#file(GLOB_RECURSE CPP_FILES ${improved-potato_SOURCE_DIR}/src/*.cpp)
#include_directories(${GLUS_INCLUDE_DIR})
#link_directories(${GLUS_LIBRARY_DIR})

