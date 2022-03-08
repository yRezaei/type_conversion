#include <boost/lexical_cast.hpp>
#include <type_conversion.hpp>
#include <benchmark/benchmark.h>

static const int numInt{32136763};
static const double numDouble{687312.654354};
static const std::string strInt{"6193248"};
static const std::string strDouble{"6193248.67612"};

static void BM_Boost_Lexical_Cast(benchmark::State& state) {
  for (auto _ : state) {
      auto str1 = boost::lexical_cast<std::string>(numInt);
      auto str2 = boost::lexical_cast<std::string>(numDouble);
      auto num1 = boost::lexical_cast<int>(strInt);
      //auto num2 = boost::lexical_cast<int>(strDouble);
  }
}

BENCHMARK(BM_Boost_Lexical_Cast);


static void BM_standard_functions(benchmark::State& state) {
  for (auto _ : state) {
      auto str1 = convert::to<std::string>(numInt);
      auto str2 = convert::to<std::string>(numDouble);
      auto num1 = convert::to<int>(strInt);
      //auto num2 = convert::to<int>(strDouble);
  }
}
BENCHMARK(BM_standard_functions);

BENCHMARK_MAIN();