#include <gtest/gtest.h>
#include <vector>
#include <iterator>
#include "algorithms/search/interpolation_search.hpp"


using namespace algorithm::search;

class InterpolationSearchTest : public ::testing::Test
{
protected:
    std::vector<int> uniform_data{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> skewed_data{1, 2, 3, 4, 5, 100, 200, 300, 400, 500};
    std::vector<int> empty;
    std::vector<int> single_data{42};
    std::vector<int> equal_data{55, 55, 55, 55, 55, 55, 55};

};

TEST_F(InterpolationSearchTest, UniformDataFound)
{
    EXPECT_TRUE(interpolation_search(uniform_data.begin(), uniform_data.end(), 10));
    EXPECT_TRUE(interpolation_search(uniform_data.begin(), uniform_data.end(), 50));
    EXPECT_TRUE(interpolation_search(uniform_data.begin(), uniform_data.end(), 100));
}

// TEST_F(BinarySearchTest, VectorNotFound) 
// {
//     EXPECT_FALSE(binary_search(vec.begin(), vec.end(), 0));
//     EXPECT_FALSE(binary_search(vec.begin(), vec.end(), 4));
//     EXPECT_FALSE(binary_search(vec.begin(), vec.end(), 10));
// }

// TEST_F(BinarySearchTest, ArrayAndDeque) 
// {
//     EXPECT_TRUE(binary_search(arr.begin(), arr.end(), 3));
//     EXPECT_FALSE(binary_search(arr.begin(), arr.end(), 6));

//     EXPECT_TRUE(binary_search(dq.begin(), dq.end(), 20));
//     EXPECT_FALSE(binary_search(dq.begin(), dq.end(), 25));
// }

// TEST_F(BinarySearchTest, EmptyAndSingle) {
//     EXPECT_FALSE(binary_search(empty.begin(), empty.end(), 42));

//     EXPECT_TRUE(binary_search(single.begin(), single.end(), 42));
//     EXPECT_FALSE(binary_search(single.begin(), single.end(), 0));
// }