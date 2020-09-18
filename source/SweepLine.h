#pragma once

#include <algorithm>
#include <iterator>
#include <queue>

#include "GeometryTypes.h"
#include "SortedSequence.h"

namespace geometry
{
    using MaxPriorityQueue = std::priority_queue<Event, std::vector<Event>, CompareEventAsc>;
    using SegmentSeq = SortedSequence<Segment>;

    void planeSweep(const SegmentSeq& segments, IntersectionSeq& intersections);

    void handleEvent(
        const Event& event, 
        MaxPriorityQueue& queue, 
        SegmentSeq& sequence, 
        IntersectionSeq& intersections);

    void handleStartEvent(
        const float& y, 
        const Segment& segment, 
        MaxPriorityQueue& queue, 
        SegmentSeq& sequence);

    void handleIntersectEvent(
        const float& y, 
        const Segment& s, 
        const Segment& t,
        MaxPriorityQueue& queue, 
        SegmentSeq& sequence, 
        IntersectionSeq& intersections);

    void handleFinishEvent(
        const float& y, 
        const Segment& segment, 
        MaxPriorityQueue& queue, 
        SegmentSeq& sequence);

    void findNewEvent(
        const float& y, 
        const Segment& a, 
        const Segment& b, 
        MaxPriorityQueue& queue);
}