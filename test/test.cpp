#include <gtest/gtest.h>
#include <type_conversion.hpp>

TEST(Convert_to_string, from_bool)
{
  EXPECT_EQ(std::string("1"), convert::to<std::string>(true));
  EXPECT_EQ(std::string("0"), convert::to<std::string>(false));
}

TEST(Convert_to_string, from_integral)
{
  EXPECT_EQ(std::string("456"), convert::to<std::string>(static_cast<std::int16_t>(456)));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321l));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321ll));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321u));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321ul));
  EXPECT_EQ(std::string("654321"), convert::to<std::string>(654321ull));
  EXPECT_NE(std::string("1"), convert::to<std::string>(10));
  EXPECT_NE(std::string("0"), convert::to<std::string>(10));
}

TEST(Convert_to_string, from_floating_point)
{
  EXPECT_EQ(std::string("654321.625000"), convert::to<std::string>(654321.654f));
  EXPECT_EQ(std::string("654321.654000"), convert::to<std::string>(654321.654));
  EXPECT_EQ(std::string("654321.654000"), convert::to<std::string>(654321.654l));
}

TEST(Convert_to_bool, from_string)
{
  std::string falseStr{"FALSE"};

  EXPECT_EQ(true, convert::to<bool>("true"));
  EXPECT_EQ(true, convert::to<bool>(std::string("True")));
  EXPECT_EQ(true, convert::to<bool>(std::string("TRUE")));
  EXPECT_EQ(false, convert::to<bool>("false"));
  EXPECT_EQ(false, convert::to<bool>(std::string{"False"}));
  EXPECT_EQ(false, convert::to<bool>(falseStr));

  EXPECT_THROW(convert::to<bool>(std::string("FALSEE")), std::invalid_argument);
  EXPECT_THROW(convert::to<bool>("FALSE "), std::invalid_argument);
}

TEST(Convert_to_integral, from_string)
{
  EXPECT_EQ(6578651, convert::to<int>(std::string("6578651")));
  EXPECT_EQ(-6578651, convert::to<int>(std::string("-6578651")));
  EXPECT_EQ(6578651, convert::to<unsigned int>(std::string("6578651")));
  EXPECT_THROW(convert::to<int>(std::string("654321#")), std::invalid_argument);
  EXPECT_THROW(convert::to<int>(std::string("+-654321")), std::invalid_argument);
  EXPECT_EQ(654321, convert::to<int>(std::string(" 654321")));
  EXPECT_THROW(convert::to<int>(std::string("654321.0")), std::invalid_argument);
}

TEST(Convert_to_floating_point, from_string)
{
  EXPECT_FLOAT_EQ(657865.574f, convert::to<float>(std::string("657865.574")));
  EXPECT_FLOAT_EQ(657865.165, convert::to<double>(std::string("657865.165")));
  EXPECT_FLOAT_EQ(657865.35746l, convert::to<long double>(std::string("657865.35746")));
  EXPECT_THROW(convert::to<float>(std::string("6543 654")), std::invalid_argument);
  EXPECT_THROW(convert::to<float>(std::string("-+6543.951")), std::invalid_argument);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}