#pragma once
#include <iterator>

namespace algorithm::search {

template<typename Iterator, typename Value>
bool interpolation_search(Iterator first, Iterator last, const Value& value) noexcept
{
    while (first != last && value >= *first && value <= *std::prev(last)) {
        auto distance = std::distance(first, last);

        if (*std::prev(last) == *first) {
            return *first == value;
        }

        auto pos = first + static_cast<typename std::iterator_traits<Iterator>::difference_type>(
            static_cast<double>(value - *first) * (distance - 1) / static_cast<double>(*std::prev(last) - *first)
        );

        if (pos < first) {
            pos = first;
        } else if (pos >= last) {
            pos = std::prev(last);
        }

        if (*pos == value) {
            return true;
        } else if (*pos < value) {
            first = pos + 1;
        } else {
            last = pos;
        }
    }
    return false;
}

}