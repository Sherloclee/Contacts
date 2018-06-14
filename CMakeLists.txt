cmake_minimum_required(VERSION 3.10)
project(Contacts)


set(CMAKE_CXX_STANDARD 11)
SET(LINKS operate saveload store str)

MESSAGE(STATUS "current platform: Linux ")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs)
LINK_DIRECTORIES(libs)
include_directories(include)
add_subdirectory(src)

add_executable(Contacts Contact.cpp)
target_link_libraries(Contacts ${LINKS})