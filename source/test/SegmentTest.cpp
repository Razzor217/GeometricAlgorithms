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

BOOST_AUTO_TEST_CASE(intersectIdenticalTest)
{
    Eigen::Vector2f start(0.f, 4.f);
    Eigen::Vector2f finish(0.f, 2.f);

    Segment a(start, finish);
    Segment b(start, finish);

    Eigen::Vector2f intersection;

    BOOST_CHECK_EQUAL(a.intersect(b, intersection), false);
}

BOOST_AUTO_TEST_CASE(intersectParallelTest)
{
    Segment a(Eigen::Vector2f(0.f, 4.f), Eigen::Vector2f(0.f, 2.f));
    Segment b(Eigen::Vector2f(1.f, 4.f), Eigen::Vector2f(1.f, 2.f));

    Eigen::Vector2f intersection;

    BOOST_CHECK_EQUAL(a.intersect(b, intersection), false);
}

BOOST_AUTO_TEST_CASE(intersectLineABNegTest)
{
    Segment a(Eigen::Vector2f(0.f, 4.f), Eigen::Vector2f(0.f, 2.f));
    Segment b(Eigen::Vector2f(1.f, 6.f), Eigen::Vector2f(-1.f, 4.f));

    Eigen::Vector2f intersection;

    /*
     * line a intersects segment b s.t. t < 0
     */
    BOOST_CHECK_EQUAL(a.intersect(b, intersection), false);
}

BOOST_AUTO_TEST_CASE(intersectLineABPosTest)
{
    Segment a(Eigen::Vector2f(0.f, 4.f), Eigen::Vector2f(0.f, 2.f));
    Segment b(Eigen::Vector2f(1.f, 2.f), Eigen::Vector2f(-1.f, 0.f));

    Eigen::Vector2f intersection;

    /*
     * line a intersects segment b s.t. t > 1
     */
    BOOST_CHECK_EQUAL(a.intersect(b, intersection), false);
}

BOOST_AUTO_TEST_CASE(intersectLineBANegTest)
{
    Segment a(Eigen::Vector2f(0.f, 4.f), Eigen::Vector2f(0.f, 2.f));
    Segment b(Eigen::Vector2f(1.f, 2.f), Eigen::Vector2f(3.f, 0.f));

    Eigen::Vector2f intersection;

    /*
     * line b intersects segment a s.t. u < 0
     */
    BOOST_CHECK_EQUAL(a.intersect(b, intersection), false);
}

BOOST_AUTO_TEST_CASE(intersectLineBAPosTest)
{
    Segment a(Eigen::Vector2f(0.f, 4.f), Eigen::Vector2f(0.f, 2.f));
    Segment b(Eigen::Vector2f(-3.f, 6.f), Eigen::Vector2f(-1.f, 4.f));

    Eigen::Vector2f intersection;

    /*
     * line b intersects segment a s.t. u > 1
     */
    BOOST_CHECK_EQUAL(a.intersect(b, intersection), false);
}

BOOST_AUTO_TEST_CASE(intersectTest)
{
    Segment a(Eigen::Vector2f(0.f, 4.f), Eigen::Vector2f(0.f, 2.f));
    Segment b(Eigen::Vector2f(1.f, 4.f), Eigen::Vector2f(-1.f, 2.f));

    Eigen::Vector2f intersection;

    BOOST_CHECK_EQUAL(a.intersect(b, intersection), true);
    BOOST_CHECK_CLOSE(intersection(0), 0.f, 0.001);
    BOOST_CHECK_CLOSE(intersection(1), 3.f, 0.001);
}