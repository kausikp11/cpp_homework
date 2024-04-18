#include <gtest/gtest.h>
#include <vector>
#include <string>

#include <no_strings_attached/string_split.h>

namespace {
  // We will test this dummy function but you can test
  // any function from any library that you write too.
  int GetMeaningOfLife() {  return 42; }
}

// All tests must live within TEST* blocks
// Inside of the TEST block is a standard C++ scope
// TestTopic defines a topic of our test, e.g. NameOfFunctionTest
// TrivialEquality represents the name of this particular test
// It should be descriptive and readable to the user
// TEST is a macro, i.e., preprocessor replaces it with some code
TEST(TestTopic, TrivialEquality) {
  // We can test for equality, inequality etc.
  // If the equality does not hold, the test fails.
  // EXPECT_* are macros, i.e., also replaced by the preprocessor.
  EXPECT_EQ(GetMeaningOfLife(), 42);
}

TEST(TestTopic,HelloWorldSplit){
    std::vector<std::string> assert_value = {"hello", "world"};
    EXPECT_EQ(no_strings_attached::string_split::Split("hello world", " "),assert_value)<<"No a problem";
}

TEST(TestTopic,RandomString){
    std::vector<std::string> assert_value = {"", "ab", "ba"};
    EXPECT_EQ(no_strings_attached::string_split::Split("aaabaaba", "aa"),assert_value)<<"No a problem";
}