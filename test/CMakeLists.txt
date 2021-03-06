cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(TESTS_NAME UnitTests)

project(${TESTS_NAME} LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage("gh:onqtam/doctest#2.4.5")
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.0")

if(TEST_INSTALLED_VERSION)
  find_package(${LIBRARY_NAME} REQUIRED)
else()
  CPMAddPackage(NAME ${LIBRARY_NAME} SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)
endif()

# ---- Create binary ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(${TESTS_NAME} ${sources})
target_link_libraries(${TESTS_NAME} doctest::doctest ${LIBRARY_NAME}::${LIBRARY_NAME})
set_target_properties(${TESTS_NAME} PROPERTIES CXX_STANDARD 17)

# enable compiler warnings
if(NOT TEST_INSTALLED_VERSION)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(${LIBRARY_NAME} PUBLIC -Wall -Wpedantic -Wextra -Werror)
  elseif(MSVC)
    target_compile_options(${LIBRARY_NAME} PUBLIC /W4 /WX)
    target_compile_definitions(${TESTS_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
  endif()
endif()

# ---- Add GreeterTests ----

enable_testing()

# Note: doctest and similar testing frameworks can automatically configure CMake tests. For other
# testing frameworks add the tests target instead: add_test(NAME greeterTests COMMAND GreeterTests)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${TESTS_NAME})

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(${LIBRARY_NAME} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(${LIBRARY_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
endif()
