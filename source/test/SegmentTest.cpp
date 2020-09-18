#define BOOST_TEST_MODULE Geometry::Segment

#include <boost/test/included/unit_test.hpp>
#include "../Segment.h"

#include <iostream>

using namespace geometry;

BOOST_AUTO_TEST_CASE(constructorTest)
{
    Segment s;

    BOOST_CHECK_CLOSE(s.getStart()(0), 0.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 0.f, 0.001);

    BOOST_CHECK_CLOSE(s.getStart()(1), std::numeric_limits<float>::max(), 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), std::numeric_limits<float>::lowest(), 0.001);
}

BOOST_AUTO_TEST_CASE(setStartTest)
{
    Segment s;

    s.setStart(Eigen::Vector2f(2.f, 2.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 2.f, 0.001);
}

BOOST_AUTO_TEST_CASE(setFinishTest)
{
    Segment s;

    s.setFinish(Eigen::Vector2f(2.f, 2.f));

    BOOST_CHECK_CLOSE(s.getFinish()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 2.f, 0.001);
}

BOOST_AUTO_TEST_CASE(setStartFinishTest)
{
    Segment s;

    s.setStart(Eigen::Vector2f(2.f, 2.f));
    s.setFinish(Eigen::Vector2f(1.f, 1.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 1.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 1.f, 0.001);
}

BOOST_AUTO_TEST_CASE(setStartHorizontalTest)
{
    Segment s;

    s.setStart(Eigen::Vector2f(2.f, 2.f));
    s.setFinish(Eigen::Vector2f(1.f, 1.f));

    /*
     * set new start point on same horizontal plane as finish point
     */

    s.setStart(Eigen::Vector2f(0.f, 1.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 1.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 1.f, 0.001);
}

BOOST_AUTO_TEST_CASE(setFinishHorizontalTest)
{
    Segment s;

    s.setStart(Eigen::Vector2f(2.f, 2.f));
    s.setFinish(Eigen::Vector2f(1.f, 1.f));

    /*
     * set new finish point on same horizontal plane as start point
     */
    s.setFinish(Eigen::Vector2f(3.f, 2.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 1.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 1.f, 0.001);
}

BOOST_AUTO_TEST_CASE(setStartFinishBelowTest)
{
    Segment s;

    s.setStart(Eigen::Vector2f(2.f, 2.f));
    s.setFinish(Eigen::Vector2f(1.f, 1.f));

    /*
     * set new start point below finish point
     */
    s.setStart(Eigen::Vector2f(0.f, 0.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 1.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 1.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 0.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 0.f, 0.001);
}

BOOST_AUTO_TEST_CASE(setFinishStartAboveTest)
{
    Segment s;

    s.setStart(Eigen::Vector2f(2.f, 2.f));
    s.setFinish(Eigen::Vector2f(1.f, 1.f));

    /*
     * set new finish point above start point
     */
    s.setFinish(Eigen::Vector2f(3.f, 3.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 3.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 3.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 2.f, 0.001);
}

BOOST_AUTO_TEST_CASE(constructorParamsTest)
{
    Segment s(Eigen::Vector2f(2.f, 2.f), Eigen::Vector2f(1.f, 1.f));

    BOOST_CHECK_CLOSE(s.getStart()(0), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getStart()(1), 2.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(0), 1.f, 0.001);
    BOOST_CHECK_CLOSE(s.getFinish()(1), 1.f, 0.001);
}

