cmake_minimum_required(VERSION 3.0.0)
project(vscode_cmake VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
#set(CMAKE_SOURCE_DIR /path/to/your/libraries)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(src ${CMAKE_SOURCE_DIR}/source)

add_executable(vscode_cmake ${src}/histogram.cpp)
#add_library(tmplib STATIC tmplib.cc)

target_compile_options(vscode_cmake PRIVATE -g -Wall -std=c++11)
target_include_directories(vscode_cmake PUBLIC  ${CMAKE_SOURCE_DIR}/lib/opencv/build/include ${CMAKE_SOURCE_DIR}/header)
#find_package(OpenCV REQUIRED)
target_link_libraries(vscode_cmake PUBLIC ${CMAKE_SOURCE_DIR}/lib/opencv/build/x64/vc16/lib/opencv_world480.lib ${CMAKE_SOURCE_DIR}/lib/opencv/build/x64/vc16/lib/opencv_world480d.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
