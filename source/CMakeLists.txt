find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_definitions(-DBOOST_TEST_DYN_LINK)
endif()

find_package(Eigen3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS})

set(SOURCES 
    Segment.cpp
    SweepLine.cpp
)

set(HEADERS
    Segment.h
    SortedSequence.h
    SweepLine.h
)

add_library(Geometry ${HEADERS} ${SOURCES})

set(LIBS
    ${Boost_LIBRARIES}
    Geometry
)

add_executable(segmentTest test/SegmentTest.cpp)
add_executable(sortedSequenceTest test/sortedSequenceTest)
add_executable(sweepLineTest test/SweepLineTest.cpp)

target_link_libraries(segmentTest ${LIBS})
target_link_libraries(sortedSequenceTest ${LIBS})
target_link_libraries(sweepLineTest ${LIBS})

add_test(NAME SegmentTest COMMAND segmentTest)
add_test(NAME sortedSequenceTest COMMAND sortedSequenceTest)
add_test(NAME SweepLineTest COMMAND sweepLineTest)
