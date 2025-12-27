#include <gtest/gtest.h>
#include <vector>
#include <array>
#include <deque>
#include <iterator>
#include "algorithms/search/binary_search.hpp"


using namespace algorithm::search;

class BinarySearchTest : public ::testing::Test
{
protected:
    std::vector<int> vec{1, 3, 5, 7, 9};
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    std::deque<int> dq{10, 20, 30, 40};
    std::vector<int> empty;
    std::vector<int> single{42};

};

TEST_F(BinarySearchTest, VectorFound)
{
    EXPECT_TRUE(binary_search(vec.begin(), vec.end(), 1));
    EXPECT_TRUE(binary_search(vec.begin(), vec.end(), 5));
    EXPECT_TRUE(binary_search(vec.begin(), vec.end(), 9));
}

TEST_F(BinarySearchTest, VectorNotFound) 
{
    EXPECT_FALSE(binary_search(vec.begin(), vec.end(), 0));
    EXPECT_FALSE(binary_search(vec.begin(), vec.end(), 4));
    EXPECT_FALSE(binary_search(vec.begin(), vec.end(), 10));
}

TEST_F(BinarySearchTest, ArrayAndDeque) 
{
    EXPECT_TRUE(binary_search(arr.begin(), arr.end(), 3));
    EXPECT_FALSE(binary_search(arr.begin(), arr.end(), 6));

    EXPECT_TRUE(binary_search(dq.begin(), dq.end(), 20));
    EXPECT_FALSE(binary_search(dq.begin(), dq.end(), 25));
}

TEST_F(BinarySearchTest, EmptyAndSingle) {
    EXPECT_FALSE(binary_search(empty.begin(), empty.end(), 42));

    EXPECT_TRUE(binary_search(single.begin(), single.end(), 42));
    EXPECT_FALSE(binary_search(single.begin(), single.end(), 0));
}