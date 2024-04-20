#include <gtest/gtest.h>
#include <string>

#include <no_strings_attached/string_trim.h>

TEST(TestTopic,hellokLeft){
    std::string assert_value = "hello ";
    EXPECT_EQ(no_strings_attached::Trim(" hello ", ' ', no_strings_attached::Side::kLeft),assert_value)<<"No a problem";
}

TEST(TestTopic,hellokRight){
    std::string assert_value = " hello";
    EXPECT_EQ(no_strings_attached::Trim(" hello ", ' ', no_strings_attached::Side::kRight),assert_value)<<"No a problem";
}

TEST(TestTopic,hellokBoth){
    std::string assert_value = " hello";
    EXPECT_EQ(no_strings_attached::Trim(" hello ", ' ', no_strings_attached::Side::kBoth),assert_value)<<"No a problem";
}

TEST(TestTopic,hellokLeftwithh){
    std::string assert_value = "ello";
    EXPECT_EQ(no_strings_attached::Trim("hello", 'h', no_strings_attached::Side::kLeft),assert_value)<<"No a problem";
}
