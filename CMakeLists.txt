cmake_minimum_required(VERSION 3.28.3)
project(OpenGLApp)

set(EXPORT_COMPILE_COMMANDS)
set(OpenGL_GL_PREFERENCE GLVND)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(source_dir "${PROJECT_SOURCE_DIR/src/}")
set(include_dir "${PROJECT_SOURCE_DIR/include/}")

file(GLOB source_files "${source_dir}/*.cpp")
include_directories(GLOB include_dir "/*.hpp")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(OpenGLApp ./src/Test.cpp)

target_link_libraries(OpenGLApp PRIVATE OpenGL::GL glfw)
