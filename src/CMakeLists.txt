cmake_minimum_required(VERSION 3.0.0)
project(engine VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories ("${PROJECT_SOURCE_DIR}/math")
add_subdirectory (math)

include_directories ("${PROJECT_SOURCE_DIR}/geometry")
add_subdirectory (geometry)

include_directories ("${PROJECT_SOURCE_DIR}/rendering")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory (rendering)

include_directories ("${PROJECT_SOURCE_DIR}/test")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory (test) 

include_directories ("${PROJECT_SOURCE_DIR}/playground")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory (playground) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

