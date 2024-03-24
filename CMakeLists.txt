cmake_minimum_required(VERSION 3.28.3)
project(OpenGLApp)

set(OpenGL_GL_PREFERENCE GLVND)
set(BOOL EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
set(include_dir "${PROJECT_SOURCE_DIR}/include/")
set(test_source_dir "${PROJECT_SOURCE_DIR}/test/")

include_directories(${include_dir})
file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB include_files "${include_dir}/*.cpp")
file(GLOB test_source_files "${test_source_dir}/*.cpp")

find_package(glfw3 REQUIRED)
find_package(OpenAL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW 2.0 REQUIRED)

add_executable(OpenGLApp ${include_files} ${source_files} ${test_source_files})

target_link_libraries(OpenGLApp PRIVATE OpenGL::GL glfw GLEW::GLEW
                                        OpenAL::OpenAL)
