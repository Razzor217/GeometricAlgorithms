find_package(Boost QUIET)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

find_package(Eigen3 QUIET)
if(Eigen3_FOUND)
    include_directories(${Eigen3_INCLUDE_DIR})
endif()

set(LIBS
    ${Boost_LIBRARIES}
)

set(SOURCES 
    ./test/SweepLineTest.cpp
)

set(HEADERS

)

add_executable(sweepLineTest ${HEADERS} ${SOURCES})
target_link_libraries(sweepLineTest ${LIBS})

add_test(NAME SweepLineTest COMMAND sweepLineTest)