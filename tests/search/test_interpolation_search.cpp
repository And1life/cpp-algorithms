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
    std::vector<int> empty_data;
    std::vector<int> single_data{42};
    std::vector<int> equal_data{55, 55, 55, 55, 55, 55, 55};

};

TEST_F(InterpolationSearchTest, UniformDataFound)
{
    EXPECT_TRUE(interpolation_search(uniform_data.begin(), uniform_data.end(), 10));
    EXPECT_TRUE(interpolation_search(uniform_data.begin(), uniform_data.end(), 50));
    EXPECT_TRUE(interpolation_search(uniform_data.begin(), uniform_data.end(), 100));
}

TEST_F(InterpolationSearchTest, UniformDataNotFound)
{
    EXPECT_FALSE(interpolation_search(uniform_data.begin(), uniform_data.end(), 1));
    EXPECT_FALSE(interpolation_search(uniform_data.begin(), uniform_data.end(), 45));
    EXPECT_FALSE(interpolation_search(uniform_data.begin(), uniform_data.end(), 87));
}

TEST_F(InterpolationSearchTest, SkewedDataFound)
{
    EXPECT_TRUE(interpolation_search(skewed_data.begin(), skewed_data.end(), 1));
    EXPECT_TRUE(interpolation_search(skewed_data.begin(), skewed_data.end(), 100));
    EXPECT_TRUE(interpolation_search(skewed_data.begin(), skewed_data.end(), 500));
}

TEST_F(InterpolationSearchTest, EmptyAndSingle) 
{
    EXPECT_FALSE(interpolation_search(empty_data.begin(), empty_data.end(), 42));
    EXPECT_TRUE(interpolation_search(single_data.begin(), single_data.end(), 42));
    EXPECT_FALSE(interpolation_search(single_data.begin(), single_data.end(), 0));
}

TEST_F(InterpolationSearchTest, EqualDataFound)
{
    EXPECT_TRUE(interpolation_search(equal_data.begin(), equal_data.end(), 55));
}

TEST_F(InterpolationSearchTest, EqualDataNotFound)
{
    EXPECT_FALSE(interpolation_search(equal_data.begin(), equal_data.end(), 9));
}