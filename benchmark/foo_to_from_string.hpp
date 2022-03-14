#ifndef C0A5A4D8_B6E3_445D_B362_2DF2DB21D7D8
#define C0A5A4D8_B6E3_445D_B362_2DF2DB21D7D8

#include <boost/lexical_cast.hpp>
#include <type_conversion.hpp>
#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>

#define VARIABLE_To_STRING(name) #name

enum class MaritalStatus : std::uint32_t
{
    MARRIED,
    SINGLE
};

enum class Sex : std::uint32_t
{
    MALE,
    FEMALE
};

struct Foo
{
    std::string name{};
    std::uint16_t age{};
    std::string address{};
    MaritalStatus maritalStatus{};
    Sex sex{};
    unsigned long long telephone{};
};

inline std::vector<std::string> split(std::string const &src, std::string const &delim)
{
    std::vector<std::string> tokens;
    int start = 0;
    int end = src.find(delim);
    while (end != -1)
    {
        tokens.emplace_back(src.substr(start, end - start));
        start = end + delim.size();
        end = src.find(delim, start);
    }
    tokens.emplace_back(src.substr(start, end - start));
    return tokens;
}

inline void to_string_std(Foo const &foo)
{
    auto str = std::string("name:") + foo.name + ", age:" + convert::to<std::string>(foo.age) + ", address:" + foo.address + 
    ", maritalStatus:" + convert::to<std::string>(static_cast<std::underlying_type_t<MaritalStatus>>(foo.maritalStatus)) + 
    ", sex:" + convert::to<std::string>(static_cast<std::underlying_type_t<Sex>>(foo.sex)) + 
    ", telephone:" + convert::to<std::string>(foo.telephone);
}

inline void from_string_std(std::string const &src, Foo &foo)
{
    auto items = split(src, ", ");
    for (auto &item : items)
    {
        auto tokens = split(item, ":");
        if (tokens[0] == "name")
        {
            foo.name = tokens[1];
        }
        else if (tokens[0] == "age")
        {
            foo.age = convert::to<std::uint16_t>(tokens[1]);
        }
        else if (tokens[0] == "address")
        {
            foo.address = tokens[1];
        }
        else if (tokens[0] == "maritalStatus")
        {
            foo.maritalStatus = static_cast<MaritalStatus>(convert::to<std::uint32_t>(tokens[1]));
        }
        else if (tokens[0] == "sex")
        {
            foo.sex = static_cast<Sex>(convert::to<std::uint32_t>(tokens[1]));
        }
        else if (tokens[0] == "telephone")
        {
            foo.telephone = convert::to<unsigned long long>(tokens[1]);
        }
    }
}

inline void to_string_boost(Foo const &foo)
{
    auto str = std::string("name:") + foo.name + ", age:" + boost::lexical_cast<std::string>(foo.age) +
               ", address:" + foo.address +
               ", maritalStatus:" + boost::lexical_cast<std::string>(static_cast<std::underlying_type_t<MaritalStatus>>(foo.maritalStatus)) +
               ", sex:" + boost::lexical_cast<std::string>(static_cast<std::underlying_type_t<Sex>>(foo.sex)) +
               ", telephone:" + boost::lexical_cast<std::string>(foo.telephone);
}

inline void from_string_boost(std::string const &src, Foo &foo)
{
    auto items = split(src, ", ");
    for (auto &item : items)
    {
        auto tokens = split(item, ":");
        if (tokens[0] == "name")
        {
            foo.name = tokens[1];
        }
        else if (tokens[0] == "age")
        {
            foo.age = boost::lexical_cast<std::uint16_t>(tokens[1]);
        }
        else if (tokens[0] == "address")
        {
            foo.address = tokens[1];
        }
        else if (tokens[0] == "maritalStatus")
        {
            foo.maritalStatus = static_cast<MaritalStatus>(boost::lexical_cast<std::uint32_t>(tokens[1]));
        }
        else if (tokens[0] == "sex")
        {
            foo.sex = static_cast<Sex>(boost::lexical_cast<std::uint32_t>(tokens[1]));
        }
        else if (tokens[0] == "telephone")
        {
            foo.telephone = boost::lexical_cast<unsigned long long>(tokens[1]);
        }
    }
}

static void to_string_std(benchmark::State &state)
{
    for (auto _ : state)
    {
        Foo foo{"jack", 35, "some address", MaritalStatus::SINGLE, Sex::MALE, 8003541669};
        to_string_std(foo);
    }
}

static void from_string_std(benchmark::State &state)
{
    Foo foo;
    for (auto _ : state)
    {
        from_string_std("name:jack,age:35,address:some address,maritalStatus:1,sex:0,telephone:8003541669", foo);
    }
}

static void to_string_boost(benchmark::State &state)
{
    for (auto _ : state)
    {
        Foo foo{"jack", 35, "some address", MaritalStatus::SINGLE, Sex::MALE, 8003541669};
        to_string_boost(foo);
    }
}

static void from_string_boost(benchmark::State &state)
{
    Foo foo;
    for (auto _ : state)
    {
        from_string_boost("name:jack,age:35,address:some address,maritalStatus:1,sex:0,telephone:8003541669", foo);
    }
}

#endif /* C0A5A4D8_B6E3_445D_B362_2DF2DB21D7D8 */
