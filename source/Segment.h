#pragma once

#include <limits>

#include <Eigen/Dense>

namespace geometry
{
    class Segment
    {
    public:
        Segment();

        Segment(const Eigen::Vector2f& a, const Eigen::Vector2f& b);

        bool intersect(const Segment& other, Eigen::Vector2f& intersection) const;

        void setStart(const Eigen::Vector2f& start);

        Eigen::Vector2f getStart() const;

        void setFinish(const Eigen::Vector2f& finish);

        Eigen::Vector2f getFinish() const;

    private:
        Eigen::Vector2f start;
        Eigen::Vector2f finish;
    };
}