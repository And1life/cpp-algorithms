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
    EXPECT_TRUE(linear_search(vec_sorted.begin(), vec_sorted.end(), 1));
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

TEST_F(LinearSearchTest, Found_LastPosition)
{
    EXPECT_TRUE(linear_search(vec_sorted.begin(), vec_sorted.end(), 9));
    EXPECT_TRUE(linear_search(vec_unsorted.begin(), vec_unsorted.end(), 10));
    EXPECT_TRUE(linear_search(lst.begin(), lst.end(), 40));
    EXPECT_TRUE(linear_search(arr.begin(), arr.end(), 4));
    EXPECT_TRUE(linear_search(set_unique.begin(), set_unique.end(), 9));
}

TEST_F(LinearSearchTest, NotFound)
{
    EXPECT_FALSE(linear_search(vec_sorted.begin(), vec_sorted.end(), 11));
    EXPECT_FALSE(linear_search(vec_unsorted.begin(), vec_unsorted.end(), 54));
    EXPECT_FALSE(linear_search(lst.begin(), lst.end(), 78));
    EXPECT_FALSE(linear_search(arr.begin(), arr.end(), -4));
    EXPECT_FALSE(linear_search(set_unique.begin(), set_unique.end(), 71));
}

TEST_F(LinearSearchTest, EmptyRange) 
{
    std::vector<int> empty;
    EXPECT_FALSE(linear_search(empty.begin(), empty.end(), 42));
}

TEST_F(LinearSearchTest, SingleElement_Found)
{
    std::vector<int> single{42};
    EXPECT_TRUE(linear_search(single.begin(), single.end(), 42));
}

TEST_F(LinearSearchTest, SingleElement_NotFound) 
{
    std::vector<int> single{42};
    EXPECT_FALSE(linear_search(single.begin(), single.end(), 99));
}

TEST_F(LinearSearchTest, EqualElements) 
{
    std::vector<int> equals{5, 5, 5, 5};
    EXPECT_TRUE(linear_search(equals.begin(), equals.end(), 5));
}

TEST_F(LinearSearchTest, DifferentTypes) 
{
    std::vector<size_t> sizes{10, 20, 30};
    EXPECT_TRUE(linear_search(sizes.begin(), sizes.end(), 20));
}


TEST_F(LinearSearchTest, Strings) 
{
    std::vector<std::string> words{"cat", "dog", "bird"};
    EXPECT_TRUE(linear_search(words.begin(), words.end(), "dog"));
    EXPECT_FALSE(linear_search(words.begin(), words.end(), "fish"));
}


TEST_F(LinearSearchTest, CArray) 
{
    int c_array[] = {100, 200, 300};
    EXPECT_TRUE(linear_search(std::begin(c_array), std::end(c_array), 200));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}