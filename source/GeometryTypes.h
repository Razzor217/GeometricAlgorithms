#pragma once

#include <vector>
#include "Segment.h"

namespace geometry
{
    enum EventType
    {
        start,
        intersection,
        finish
    };

    struct Event
    {
        Event(const float& y, const EventType& type, const Segment& segment) 
         : y(y), type(type), segment(segment)
        {
            
        }

        float y;
        EventType type;
        Segment segment;
    };

    struct Intersection
    {
        Intersection(const Eigen::Vector2f& intersection, const Segment& first, const Segment& second) 
         : intersection(intersection), first(first), second(second)
        {
            
        }

        Eigen::Vector2f intersection;
        Segment first;
        Segment second;
    };

    using IntersectionSeq = std::vector<Intersection>;

    class CompareEventAsc
    {
    public:
        bool operator()(const Event& a, const Event& b)
        {
            return a.y < b.y;
        }
    };

    class CompareSegmentAsc
    {
    public:
        bool operator()(const Segment& a, const Segment& b)
        {
            return a.getStart()(0) < b.getStart()(0);
        }
    };
}