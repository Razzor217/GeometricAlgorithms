#pragma once

#include <vector>
#include <algorithm>

namespace geometry
{
    template<typename T>
    class SortedSequence : public std::vector<T>
    {
    public:
        template<typename P>
        typename std::vector<T>::iterator insert_sorted(const T& value, P pred)
        {
            return this->insert(std::upper_bound(this->begin(), this->end(), value, pred), value);
        }
    };
}