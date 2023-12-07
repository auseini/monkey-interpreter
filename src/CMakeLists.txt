cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES CMAKE_CURRENT_LIST_DIR "*.cpp")

add_executable(interpreter ${SOURCE_FILES})
