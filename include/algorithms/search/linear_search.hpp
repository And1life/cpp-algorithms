#pragma once
#include <iterator>

namespace algorithm::search {

template<typename Iterator, typename Value>
bool linear_search(Iterator first, Iterator last, Value value) noexcept
{
    for (Iterator it = first; it != last; ++it)
    {
        if (*it == value)
        {
            return true;
        }
    }
    return false;
}

}
