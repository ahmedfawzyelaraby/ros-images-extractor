#project name and minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3)
PROJECT(ros-bag-image-extractor)

#c++ version
ADD_COMPILE_OPTIONS(-std=c++14)

#find Boost library
FIND_PACKAGE(Boost REQUIRED program_options)

#find ROS library


#add the path of includes to includes search path
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/include")

#build the source code
FILE(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
ADD_EXECUTABLE(${PROJECT_NAME} "${SOURCES}")
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${Boost_LIBRARIES})