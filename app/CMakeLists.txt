cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(APP_NAME App)

project(${APP_NAME} LANGUAGES CXX)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(NAME ${LIBRARY_NAME} SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create standalone executable ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(${APP_NAME} ${sources})

set_target_properties(${APP_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME ${LIBRARY_NAME})

target_link_libraries(${APP_NAME} ${LIBRARY_NAME}::${LIBRARY_NAME})
