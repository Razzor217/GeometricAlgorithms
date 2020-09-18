#pragma once

#include <vector>
#include <algorithm>

namespace geometry
{
    /**
     * @brief Vector data structure allowing insertion of elements in a 
     * sorted manner.
     * 
     * @tparam T Type of the elements
     */
    template<typename T>
    class SortedSequence : public std::vector<T>
    {
    public:
        /**
         * @brief Inserts an element into the vector in a sorted manner.
         *
         * For example, \f$ n \times \f$ `insert_sorted` into an empty vector 
         * yields a sorted vector.
         * 
         * @tparam P        Binary predicate function type
         * @param value     Element to insert
         * @param pred      Binary predicate which returns `true` if the first argument
         *                  is less than the second. The function signature should be
         *                  equivalent to `bool pred(const T& a, const T& b)`.
         * @return An iterator pointing to the inserted element.
         */
        template<typename P>
        typename std::vector<T>::iterator insert_sorted(const T& value, P pred)
        {
            return this->insert(std::upper_bound(this->begin(), this->end(), value, pred), value);
        }

        /**
         * @brief Inserts an element into the vector in a sorted manner.
         * 
         * For example, \f$ n \times \f$ `insert_sorted` into an empty vector 
         * yields a sorted vector.
         *
         * @param value     Element to insert
         * @return An iterator pointing to the inserted element.
         */
        typename std::vector<T>::iterator insert_sorted(const T& value)
        {
            return this->insert(std::upper_bound(this->begin(), this->end(), value), value);
        }
    };
}