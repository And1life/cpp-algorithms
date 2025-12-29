#include <gtest/gtest.h>
#include <vector>
#include <iterator>
#include "algorithms/search/naive_string_search.hpp"

using namespace algorithm::search;

class NaiveStringSearchTest : public ::testing::Test
{

protected:

    static constexpr size_t NPOS = std::string::npos;
};

TEST_F(NaiveStringSearchTest, FoundAtBeginning) 
{
    EXPECT_EQ(naive_string_search("abcabc", "abc"), 0);
}

TEST_F(NaiveStringSearchTest, FoundInMiddle) 
{
    EXPECT_EQ(naive_string_search("xabcy", "abc"), 1);
}

TEST_F(NaiveStringSearchTest, FoundInEnd) 
{
    EXPECT_EQ(naive_string_search("abacabc", "bc"), 5);
}

TEST_F(NaiveStringSearchTest, NotFound) 
{
    EXPECT_EQ(naive_string_search("abc", "def"), NPOS);
    EXPECT_EQ(naive_string_search("abc", "abx"), NPOS);
}

TEST_F(NaiveStringSearchTest, PatternLongerThanTextByOne) 
{
    EXPECT_EQ(naive_string_search("abc", "abcd"), NPOS); 
}

TEST_F(NaiveStringSearchTest, SingleCharacter) 
{
    EXPECT_EQ(naive_string_search("abc", "b"), 1);
}

TEST_F(NaiveStringSearchTest, AllIdenticalChars) 
{
    EXPECT_EQ(naive_string_search("aaaaa", "aaa"), 0);
}