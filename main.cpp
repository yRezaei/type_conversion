#include <iostream>
#include "time_it.hpp"
#include <boost/lexical_cast.hpp>
#include "conversion.hpp"

auto timeFuncInvocation =
    [](auto &&func, auto &&...params)
{
    // get time before function invocation
    const auto &start = std::chrono::high_resolution_clock::now();
    // function invocation using perfect forwarding
    for (auto i = 0; i < 100000 /*largeNumber*/; ++i)
    {
        std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
    }
    // get time after function invocation
    const auto &stop = std::chrono::high_resolution_clock::now();
    return (stop - start) / 100000 /*largeNumber*/;
};

void boost_lexical_cast_int()
{
    TimeIt t(__FUNCTION__, 100000);
    t.start();
    for (auto i = 0u; i < 100000; ++i)
        boost::lexical_cast<std::string>(100);
    t.stop();
}
void std_convert_int()
{
    TimeIt t(__FUNCTION__, 100000);
    t.start();
    for (auto i = 0u; i < 100000; ++i)
        convert::to<std::string>(100);
    t.stop();
}

void boost_lexical_cast_float()
{
    TimeIt t(__FUNCTION__, 100000);
    t.start();
    for (auto i = 0u; i < 100000; ++i)
        boost::lexical_cast<std::string>(100.01f);
    t.stop();
}
void std_convert_float()
{
    TimeIt t(__FUNCTION__, 100000);
    t.start();
    for (auto i = 0u; i < 100000; ++i)
        convert::to<std::string>(100.01f);
    t.stop();
}

void boost_lexical_cast_char()
{
    TimeIt t(__FUNCTION__, 100000);
    t.start();
    for (auto i = 0u; i < 100000; ++i)
        boost::lexical_cast<int>("654");
    t.stop();
}
void std_convert_char()
{
    TimeIt t(__FUNCTION__, 100000);
    t.start();
    for (auto i = 0u; i < 100000; ++i)
        convert::to<int>("654");
    t.stop();
}

int main()
{
    {
        boost_lexical_cast_int();
        std_convert_int();
    }
    {
        boost_lexical_cast_float();
        std_convert_float();
    }
    {
        boost_lexical_cast_char();
        std_convert_char();
    }

    return 0;
}