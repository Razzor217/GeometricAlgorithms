#define BOOST_TEST_MODULE Geometry::SortedSequence

#include <boost/test/included/unit_test.hpp>
#include "../SortedSequence.h"

#include <Eigen/Dense>
#include <iostream>

using namespace geometry;

/*
 * predicate signature
 * bool pred(const Type1 &a, const Type2 &b);
 */
bool compVec2fAsc(const Eigen::Vector2f& a, const Eigen::Vector2f& b)
{
    return a(0) < b(0);
}

BOOST_AUTO_TEST_CASE(insertSortedIntAscTest)
{
    SortedSequence<int> seq;

    int n = 10;
    seq.resize(n);

    for (int i = 0; i < n ; ++i)
    {
        seq.insert_sorted(i);
    }

    BOOST_CHECK(std::is_sorted(seq.begin(), seq.end()));
}

BOOST_AUTO_TEST_CASE(insertSortedIntDescTest)
{
    SortedSequence<int> seq;

    int n = 10;
    /*
     * insert in descending order but sort in ascending order
     * IO complexity is abysmal but we don't care
     */
    for (int i = n - 1; i >= 0; i--)
    {
        seq.insert_sorted(i);
    }

    BOOST_CHECK(std::is_sorted(seq.begin(), seq.end()));
}

BOOST_AUTO_TEST_CASE(insertSortedVec2fAscTest)
{
    SortedSequence<Eigen::Vector2f> seq;

    int n = 10;
     for (int i = 0; i < n; ++i)
     {
         seq.insert_sorted(Eigen::Vector2f(i, i), compVec2fAsc);
     }

    BOOST_CHECK(std::is_sorted(seq.begin(), seq.end(), compVec2fAsc));
}

BOOST_AUTO_TEST_CASE(insertSortedVec2fDescTest)
{
    SortedSequence<Eigen::Vector2f> seq;

    int n = 10;
    /*
     * insert in descending order but sort in ascending order
     * IO complexity is abysmal but we don't care
     */
    for (int i = 0; i < n; ++i)
    {
        seq.insert_sorted(Eigen::Vector2f(n - i, i + 1), compVec2fAsc);
    }

    BOOST_CHECK(std::is_sorted(seq.begin(), seq.end(), compVec2fAsc));
}