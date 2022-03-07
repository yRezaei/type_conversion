#include <gtest/gtest.h>
#include <type_conversion.hpp>

TEST(ConvertToString, Valid_numerical_input)
{
  float f = 654321.654;
  double d = 654321.654;
  EXPECT_EQ(std::string("1"), convert::to<std::string>(true));
  EXPECT_EQ(std::string("456"), convert::to<std::string>(static_cast<std::int16_t>(456)));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321l));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321ll));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321u));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321ul));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321ull));
  EXPECT_EQ(std::string("654321.625000"), convert::to<std::string>(f));
  EXPECT_EQ(std::string("654321.654000"), convert::to<std::string>(d));
}

TEST(ConvertToString, Invalid_numerical_input)
{
  EXPECT_NE(std::string("1"), convert::to<std::string>(10));
  EXPECT_NE(std::string("0"), convert::to<std::string>(10));
  EXPECT_THROW(convert::to<int>(std::string("654321#")), std::invalid_argument);
  EXPECT_THROW(convert::to<float>(std::string("-+6543.21")), std::invalid_argument);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}