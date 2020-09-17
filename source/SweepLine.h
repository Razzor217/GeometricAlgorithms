#pragma once

#include <queue>

#include "GeometryTypes.h"
#include "SortedSequence.h"

namespace geometry
{
    void planeSweep(const std::vector<Segment>& segments, IntersectionSeq& intersections)
    {
        SortedSequence<Segment> T;
        std::priority_queue<Event, std::vector<Event>, CompareEventAsc> Q;
    }
}