# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(ellipseDetection)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
# set(OpenCV_DIR )
find_package(OpenCV 4.5.5 REQUIRED)
find_package(LAPACK)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../dist)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
SET(CMAKE_BUILD_TYPE "Debug")
include(CPack)
include_directories(/Users/zihanwu/eigen/include/)
include_directories(/opt/homebrew/include/)
include_directories(/opt/homebrew/Cellar/opencv/4.5.5_1/include/opencv4/)

# print dir
get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}")

set(BLA_VENDOR APPLE)
message("${LAPACK_LIBRARIES}")
# find_package(LAPACK REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
# message(STATUS ${LDFLAGS})

# Declare the executable target built from your sources
add_executable(${PROJECT_NAME} main.cpp Find_arcs.hpp Find_arcs.cpp Debug.hpp Debug.cpp)
add_compile_options(-Wwritable-strings)
# Link your application with OpenCV libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} LAPACK)


