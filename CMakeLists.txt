CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(leetcode)

# We always use c99
set(CMAKE_C_FLAGS "-std=c99")

# Use cmocka for unit test
include(cmake/cmocka.cmake)

# Enable ctest helpers
enable_testing()

ADD_SUBDIRECTORY(src)
