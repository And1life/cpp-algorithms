#pragma once
#include <iterator>

namespace algorithm::search {

template<typename Iterator, typename Value>
bool binary_search(Iterator first, Iterator last, const Value& value) noexcept
{
    while (first != last)
    {
        auto distance = std::distance(first, last);
        Iterator mid = first + distance / 2;

        if (*mid == value)
        {
            return true;
        }

        if (*mid < value)
        {
            first = mid + 1;
        } else {
            last = mid;
        }
    }

    return false;
}

}