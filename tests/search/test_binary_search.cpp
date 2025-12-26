#include <gtest/gtest.h>
#include <vector>

#include <string>
#include <iterator>
#include "algorithms/search/binary_search.hpp"


using namespace algorithm::search;

class BinarySearchTest : public ::testing::Test
{
protected:
    std::vector<int> vec_sorted{1, 3, 5, 7, 9};

};

TEST_F(BinarySearchTest, Found_FirstPosition)
{
    EXPECT_TRUE(binary_search(vec_sorted.begin(), vec_sorted.end(), 1));

}
