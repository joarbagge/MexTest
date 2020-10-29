cmake_minimum_required(VERSION 2.8)
project(MEX)

# This block might be necessary if you have an old version of
# CMake but a recent version of Matlab.
if(CMAKE_VERSION VERSION_LESS "3.18")
  message(WARNING "CMake version less than 3.18 detected"
    " -- using local FindMatlab module extracted from v3.18")
  # Where we keep the FindMatlab module
  set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake-compat
    ${CMAKE_MODULE_PATH})
endif()

find_package(Matlab REQUIRED MAIN_PROGRAM)
if(NOT Matlab_FOUND)
  message(FATAL_ERROR "MATLAB not found.")
else()
  message("MATLAB found.")
endif()
include_directories(
  ${Matlab_INCLUDE_DIRS}
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  # -ffast-math is for some reason not working with gcc
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -std=c99 -Wall -O3 -march=native -fopenmp")
endif()

# Add MEX files to build
matlab_add_mex(
  NAME mextest
  SRC ${PROJECT_SOURCE_DIR}/mex/mextest.c
  )
