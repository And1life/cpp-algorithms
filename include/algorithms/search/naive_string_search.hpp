#pragma once
#include <string>
#include <iterator>

namespace algorithm::search {


size_t naive_string_search(const std::string& text, const std::string& pattern) noexcept
{
    if (pattern.empty())
    {
        return 0;
    }
    if (text.size() < pattern.size())
    {
        return std::string::npos;
    }
    
    size_t n = text.size();
    size_t m = pattern.size();

    for (size_t i = 0; i < n - m; ++i)
    {
        size_t j;
        for (j  = 0; j < m; ++j)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return std::string::npos;
}
}