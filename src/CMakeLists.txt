cmake_minimum_required(VERSION 3.14)


file(GLOB SOURCE_FILES CMAKE_CURRENT_LIST_DIR "*.cpp")
file(GLOB HEADER_FILES CMAKE_CURRENT_LIST_DIR "*.h")
add_executable(interpreter ${SOURCE_FILES} ${HEADER_FILES})
add_subdirectory(test)
