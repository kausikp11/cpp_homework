#include <gtest/gtest.h>
#include <vector>
#include <string>

#include <no_strings_attached/string_split.h>

TEST(TestTopic,HelloWorldSplit){
    std::vector<std::string> assert_value = {"hello", "world"};
    EXPECT_EQ(no_strings_attached::Split("hello world", " "),assert_value)<<"No a problem";
}

TEST(TestTopic,RandomString){
    std::vector<std::string> assert_value = {"", "ab", "ba"};
    EXPECT_EQ(no_strings_attached::Split("aaabaaba", "aa"),assert_value)<<"No a problem";
}