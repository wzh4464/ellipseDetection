# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(ellipseDetection)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
# set(OpenCV_DIR )
find_package(OpenCV 4.5.4 REQUIRED)
find_package(LAPACK)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
include_directories(/Users/zihanwu/eigen/include/)
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
add_executable(ellipseDetection main.cpp Find_arcs.hpp Find_arcs.cpp)
add_compile_options(-Wwritable-strings)
# Link your application with OpenCV libraries
target_link_libraries(ellipseDetection PRIVATE ${OpenCV_LIBS} LAPACK)


