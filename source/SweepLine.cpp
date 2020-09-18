#include "SweepLine.h"

using namespace geometry;

void planeSweep(const SegmentSeq& segments, IntersectionSeq& intersections)
{
    SegmentSeq sequence;
    MaxPriorityQueue queue;

    for (auto s : segments)
    {
        queue.push(Event(s.getStart()(1), EventType::start, s, std::nullopt));
        queue.push(Event(s.getFinish()(1), EventType::finish, s, std::nullopt));
    }

    while (!queue.empty())
    {
        Event event = queue.top();
        queue.pop();
        handleEvent(event, queue, sequence, intersections);
    }
}

void handleEvent(
    const Event& event, 
    MaxPriorityQueue& queue, 
    SegmentSeq& sequence, 
    IntersectionSeq& intersections)
{
    switch (event.type)
    {
        case EventType::start:
            handleStartEvent(event.y, event.s, queue, sequence);
            break;
        case EventType::intersection:
            handleIntersectEvent(event.y, event.s, *(event.t), queue, sequence, intersections);
            break;
        case EventType::finish:
            handleFinishEvent(event.y, event.s, queue, sequence);
            break;
    }
}

void handleStartEvent(
    const float& y, 
    const Segment& segment, 
    MaxPriorityQueue& queue, 
    SegmentSeq& sequence, 
    IntersectionSeq& intersections)
{
    auto it = sequence.insert_sorted(segment);
    
    findNewEvent(y, *(std::prev(it)), *it, queue);
    findNewEvent(y, *it, *(std::next(it)), queue);
}

void handleIntersectEvent(
    const float& y, 
    const Segment& s,
    const Segment& t,
    MaxPriorityQueue& queue, 
    SegmentSeq& sequence, 
    IntersectionSeq& intersections)
{
    Eigen::Vector2f intersection;
    s.intersect(t, intersection);
    intersections.push_back(Intersection(intersection, s, t));

    auto itS = std::find(sequence.begin(), sequence.end(), s);
    auto itT = std::find(sequence.begin(), sequence.end(), t);

    std::iter_swap(itS, itT);

    findNewEvent(y, *(std::prev(itT)), *itT, queue);
    findNewEvent(y, *itS, *(std::next(itS)), queue);
}

void handleFinishEvent(
    const float& y, 
    const Segment& segment, 
    MaxPriorityQueue& queue, 
    SegmentSeq& sequence, 
    IntersectionSeq& intersections)
{
    auto it = std::find(sequence.begin(), sequence.end(), segment);

    auto prev = *(std::prev(it));
    auto next = *(std::next(it));

    sequence.erase(it);
    
    findNewEvent(y, prev, next, queue);
}

void findNewEvent(
    const float& y, 
    const Segment& a, 
    const Segment& b, 
    MaxPriorityQueue& queue)
{
    Eigen::Vector2f intersection;
    if (a.intersect(b, intersection) && intersection(1) < y)
    {
        queue.push(Event(intersection(1), EventType::intersection, a, std::make_optional(b)));
    }
}