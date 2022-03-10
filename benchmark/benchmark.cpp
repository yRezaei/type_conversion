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


static void BM_LexicalCast_int_to_string(benchmark::State &state)
{
  for (auto _ : state)
  {
    str1 = boost::lexical_cast<std::string>(numInt);
  }
}

static void BM_std_int_to_string(benchmark::State &state)
{
  for (auto _ : state)
  {
    str1 = convert::to<std::string>(numInt);
  }
}
BENCHMARK(BM_LexicalCast_int_to_string);
BENCHMARK(BM_std_int_to_string);

//########################
static void BM_LexicalCast_double_to_string(benchmark::State &state)
{
  for (auto _ : state)
  {
    str2 = boost::lexical_cast<std::string>(numDouble);
  }
}

static void BM_std_double_to_string(benchmark::State &state)
{
  for (auto _ : state)
  {
    str2 = convert::to<std::string>(numDouble);
  }
}
BENCHMARK(BM_LexicalCast_double_to_string);
BENCHMARK(BM_std_double_to_string);

//########################
static void BM_LexicalCast_string_to_int(benchmark::State &state)
{
  for (auto _ : state)
  {
    num1 = boost::lexical_cast<int>(strInt);
  }
}

static void BM_std_string_to_int(benchmark::State &state)
{
  for (auto _ : state)
  {
    num1 = convert::to<int>(strInt);
  }
}
BENCHMARK(BM_LexicalCast_string_to_int);
BENCHMARK(BM_std_string_to_int);

//########################
static void BM_LexicalCast_string_to_double(benchmark::State &state)
{
  for (auto _ : state)
  {
    num2 = boost::lexical_cast<double>(strDouble);
  }
}

static void BM_std_string_to_double(benchmark::State &state)
{
  for (auto _ : state)
  {
    num2 = convert::to<double>(strDouble);
  }
}
BENCHMARK(BM_LexicalCast_string_to_double);
BENCHMARK(BM_std_string_to_double);

//########################
static void BM_LexicalCast_string_to_bool(benchmark::State &state)
{
  for (auto _ : state)
  {
    bool1 = boost::lexical_cast<bool>("1");
  }
}

static void BM_std_string_to_bool(benchmark::State &state)
{
  for (auto _ : state)
  {
    bool1 = convert::to<bool>("1");

  }
}
BENCHMARK(BM_LexicalCast_string_to_bool);
BENCHMARK(BM_std_string_to_bool);

//########################
static void BM_LexicalCast_bool_to_string(benchmark::State &state)
{
  for (auto _ : state)
  {
    str3 = boost::lexical_cast<std::string>(false);
  }
}

static void BM_std_bool_to_string(benchmark::State &state)
{
  for (auto _ : state)
  {
    str3 = convert::to<std::string>(false);
  }
}

BENCHMARK(BM_LexicalCast_bool_to_string);
BENCHMARK(BM_std_bool_to_string);
BENCHMARK_MAIN();