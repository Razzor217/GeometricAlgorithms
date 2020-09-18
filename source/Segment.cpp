#include "Segment.h"

using namespace geometry;

Segment::Segment()
{
    float min = std::numeric_limits<float>::lowest();
    float max = std::numeric_limits<float>::max();

    start = Eigen::Vector2f(0.f, max);
    finish = Eigen::Vector2f(0.f, min);
}

Segment::Segment(const Eigen::Vector2f& a, const Eigen::Vector2f& b)
{
    float min = std::numeric_limits<float>::lowest();
    float max = std::numeric_limits<float>::max();

    start = Eigen::Vector2f(0.f, max);
    finish = Eigen::Vector2f(0.f, min);

    /*
     * avoid horizontal lines
     */
    setStart(a);
    setFinish(b);
}

// todo: check numerators / denominator
bool Segment::intersect(const Segment& other, Eigen::Vector2f& intersection) const
{
    float den = (start(0) - finish(0)) * (other.getStart()(1) - other.getFinish()(1)) 
                - (start(1) - finish(1)) * (other.getStart()(0) - other.getFinish()(0));

    /*
     * segments parallel
     */
    if (std::abs(den) < 1e-6)
    {
        return false;
    }

    float numT = (start(0) - other.getStart()(0)) * (other.getStart()(1) - other.getFinish()(1)) 
                - (start(1) - other.getStart()(1)) * (other.getStart()(0) - other.getFinish()(0));
    float numU = (start(0) - finish(0)) * (start(1) - other.getStart()(1)) 
                - (start(1) - finish(1)) * (start(0) - other.getFinish()(0));

    float t = numT / den;
    float u = numU / den;

    /*
     * intersection not within segments
     */
    if (t < 0.f || t > 1.f || u < 0.f || u > 1.f)
    {
        return false;
    }

    /*
     * first degree Bezier equation
     */
    intersection = start + t * (finish - start);
    return true;
}

void Segment::setStart(const Eigen::Vector2f& start)
{
    /*
     * no op if new start value is on same horizontal plane as finish 
     */
    if (std::abs(start(1) - this->finish(1)) < 1e-6)
    {
        return;
    }

    if (start(1) > this->finish(1))
    {
        this->start = start;
    }

    if (start(1) < this->finish(1))
    {
        /*
         * replace segment start point and
         * switch start/finish label
         */
        this->start = this->finish;
        this->finish = start;
    }
}

Eigen::Vector2f Segment::getStart() const
{
    return this->start;
}

void Segment::setFinish(const Eigen::Vector2f& finish)
{
    /*
     * no op if new finish value is on same horizontal plane as start 
     */
    if (std::abs(finish(1) - this->start(1)) < 1e-6)
    {
        return;
    }

    if (finish(1) < this->start(1))
    {
        this->finish = finish;
    }

    if (finish(1) > this->start(1))
    {
        /*
         * replace segment finish point and
         * switch start/finish label
         */
        this->finish = this->start;
        this->start = finish;
    }
}

Eigen::Vector2f Segment::getFinish() const
{
    return this->finish;
}

bool operator==(const Segment& a, const Segment& b)
{
    auto start = a.getStart() - b.getStart();
    auto finish = a.getFinish() - b.getFinish();
    return start.squaredNorm() < 1e-6 && finish.squaredNorm() < 1e-6;
}

bool operator<(const Segment& a, const Segment& b)
{
    return a.getStart()(0) < b.getStart()(0);
}