#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <string>
#include <iterator>
#include <algorithms/search/linear_search.hpp>

using namespace algorithm::search;

class LinearSearchTest : public ::testing::Test
{
protected:
    std::vector<int> vec_sorted{1, 3, 5, 7, 9};
    std::vector<int> vec_unsorted{5, 4, 8, 1, 10};
    std::list<int> lst{10, 20, 30, 20, 40};
    std::array<int, 5> arr{1, 2, 2, 3, 4};
    std::set<int> set_unique{1, 3, 5, 7, 9};

};

TEST_F(LinearSearchTest, Found_FirstPosition)
{
    EXPECT_TRUE(linear_search(vec_sorted.begin(), vec_sorted.end(), 0));
    EXPECT_TRUE(linear_search(vec_unsorted.begin(), vec_unsorted.end(), 5));
    EXPECT_TRUE(linear_search(lst.begin(), lst.end(), 10));
    EXPECT_TRUE(linear_search(arr.begin(), arr.end(), 1));
    EXPECT_TRUE(linear_search(set_unique.begin(), set_unique.end(), 1));
}

TEST_F(LinearSearchTest, Found_MiddlePosition)
{
    EXPECT_TRUE(linear_search(vec_sorted.begin(), vec_sorted.end(), 5));
    EXPECT_TRUE(linear_search(vec_unsorted.begin(), vec_unsorted.end(), 8));
    EXPECT_TRUE(linear_search(lst.begin(), lst.end(), 30));
    EXPECT_TRUE(linear_search(arr.begin(), arr.end(), 2));
    EXPECT_TRUE(linear_search(set_unique.begin(), set_unique.end(), 5));
}

