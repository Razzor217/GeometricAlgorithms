#pragma once

#include <vector>
#include <optional>

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
        Event(
            const float& y, 
            const EventType& type, 
            const Segment& s, 
            const std::optional<Segment>& t = std::nullopt) 
         : y(y), type(type), s(s), t(t)
        {
            
        }

        float y;
        EventType type;
        Segment s;
        std::optional<Segment> t;
    };

    struct Intersection
    {
        Intersection(const Eigen::Vector2f& intersection, const Segment& s, const Segment& t) 
         : intersection(intersection), s(s), t(t)
        {
            
        }

        Eigen::Vector2f intersection;
        Segment s;
        Segment t;
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

    bool compareSegmentAsc(const Segment& a, const Segment& b)
    {
        return a.getStart()(0) < b.getStart()(0);
    }
}