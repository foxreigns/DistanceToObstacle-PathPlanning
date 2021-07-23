cmake_minimum_required(VERSION 2.6)
project(coding_challenge)
add_definitions(-std=c++14)
cmake_minimum_required(VERSION 2.8.3)

add_library(${PROJECT_NAME}
	src/Angle.cpp
	src/Point2d.cpp
	src/Pose2d.cpp
	src/Vector2d.cpp
	src/Segment2d.cpp
	src/ReferencePoses.cpp)
	
include_directories(
  include)

################################
# GTest
################################
find_package(GTest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()

################################
# Unit Tests
################################
# Add test cpp file
add_executable( runUnitTests 
	test/main.cpp
	test/Point2dTest.cpp
	test/Pose2dTest.cpp
	test/Vector2dTest.cpp
	test/Segment2dTest.cpp
	test/ReferencePosesTest.cpp
	# test/ReferencePosesScoringTest.cpp
	test/AngleTest.cpp )

include_directories(
  include)
  
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} coding_challenge pthread)
add_test( runUnitTests runUnitTests )
