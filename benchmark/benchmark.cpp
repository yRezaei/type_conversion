#include <boost/lexical_cast.hpp>
#include <type_conversion.hpp>
#include <benchmark/benchmark.h>

static const int numInt{32136763};
static const double numDouble{687312.654354};
static const std::string strInt{"6193248"};
static const std::string strDouble{"6193248.676"};

static std::string str1{};
static std::string str2{};
static int num1{};
static double num2{};
static bool bool1{};
static std::string str3{};

static void BM_Boost_Lexical_Cast(benchmark::State &state)
{
  for (auto _ : state)
  {
    str1 = boost::lexical_cast<std::string>(numInt);
    str2 = boost::lexical_cast<std::string>(numDouble);
    num1 = boost::lexical_cast<int>(strInt);
    num2 = boost::lexical_cast<double>(strDouble);
    bool1 = boost::lexical_cast<bool>("1");
    str3 = boost::lexical_cast<std::string>(false);
  }
}

static void BM_standard_functions(benchmark::State &state)
{
  for (auto _ : state)
  {
    str1 = convert::to<std::string>(numInt);
    str2 = convert::to<std::string>(numDouble);
    num1 = convert::to<int>(strInt);
    num2 = convert::to<double>(strDouble);
    bool1 = convert::to<bool>("1");
    str3 = convert::to<std::string>(false);
  }
}

BENCHMARK(BM_Boost_Lexical_Cast);
BENCHMARK(BM_standard_functions);
BENCHMARK_MAIN();