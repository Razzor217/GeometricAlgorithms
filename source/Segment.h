#pragma once

#include <limits>

#include <Eigen/Dense>

namespace geometry
{
    /**
     * @brief Two-dimensional line segment defined by start and end points.
     *
     * The `start` and `finish` points are defined such that the start point 
     * lies above the finish point in the two-dimensional plane. Consequently, 
     * horizontal line segments (start and finish on same horizontal hyperplane) 
     * are prohibited.
     * 
     * The data structure provides intersection checking between two segments.
     */
    class Segment
    {
    public:
        /**
         * @brief Construct a new Segment object.
         * 
         * Start and finish points are initialized to \f$ \pm \infty \f$, respectively.
         */
        Segment();

        /**
         * @brief Construct a new Segment object.
         * 
         * @param a     Start point of the line segment
         * @param b     End point of the line segment
         */
        Segment(const Eigen::Vector2f& a, const Eigen::Vector2f& b);

        /**
         * @brief Checks whether two line segments intersect.
         * 
         * @param[in] other             Line segment to check against
         * @param[out] intersection     Point of intersection
         * @return                      `true` if the line segments intersect, 
         *                              `false` otherwise
         */
        bool intersect(const Segment& other, Eigen::Vector2f& intersection) const;

        /**
         * @brief Set the start point of the line segment.
         *
         * If the new start point lies below the current finish point, the 
         * labels are swapped. NOOP if new start and current finish point are on 
         * the same horizontal hyperplane.
         * 
         * @param start     Start point of the line segment
         */
        void setStart(const Eigen::Vector2f& start);

        /**
         * @brief Get the Start point of the line segment.
         * 
         * @return the start point of the line segment
         */
        Eigen::Vector2f getStart() const;

        /**
         * @brief Set the finish point of the line segment.
         * 
         * If the new start point lies below the current finish point, the 
         * labels are swapped. NOOP if new start and current finish point are on 
         * the same horizontal hyperplane.
         *
         * @param finish    Finish point of the line segment
         */
        void setFinish(const Eigen::Vector2f& finish);

        /**
         * @brief Get the finish point of the line segment.
         * 
         * @return the finish point of the line segment
         */
        Eigen::Vector2f getFinish() const;

        /**
         * @brief Overloads the `equal to` operator for line segments.
         *
         * Two line segments are equal if the share start and finish points.
         * 
         * @param a     First line segment
         * @param b     Second line segment
         * @return      `true` if the line segments are equal, `false` otherwise
         */
        friend bool operator==(const Segment& a, const Segment& b);

        /**
         * @brief Overloads the `less than` operator for line segments.
         * 
         * Line segment `a` is smaller than segment `b` if the start point of 
         * `a` has a smaller x-coordinate than the start point of `b`.
         * 
         * @param a     First line segment
         * @param b     Second line segment
         * @return      `true` if the first line segment is smaller than the second segment, 
         *              `false` otherwise
         */
        friend bool operator<(const Segment& a, const Segment& b);

    private:
        Eigen::Vector2f start;
        Eigen::Vector2f finish;
    };
}