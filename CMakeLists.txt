cmake_minimum_required(VERSION 3.0.0...3.5.0)
project(
  TinyXML2Example
  VERSION 1.0.0.0
  DESCRIPTION "An example usage of TinyXML via a account login system. "
  HOMEPAGE_URL "https://github.com/SomeDudeNamedAnthony/TinyXML-2-Example"
  LANGUAGES C CXX)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/external/tinyxml2-10")

add_library(
  whereami STATIC "${CMAKE_CURRENT_LIST_DIR}/external/whereami/src/whereami.c"
                  "${CMAKE_CURRENT_LIST_DIR}/external/whereami/src/whereami.h")

target_include_directories(
  whereami PUBLIC "${CMAKE_CURRENT_LIST_DIR}/external/whereami/src")

add_library(whereami::whereami ALIAS whereami)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
                               ${CMAKE_CURRENT_LIST_DIR}/src/file.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE tinyxml2::tinyxml2
                                              whereami::whereami)
