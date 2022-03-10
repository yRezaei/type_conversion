#ifndef F829904E_F0F8_4832_98A1_1E614847C8E0
#define F829904E_F0F8_4832_98A1_1E614847C8E0

#include <cstdlib>
#include <string>
#include <stdexcept>
#include <exception>
#include <utility>
#include <cstring>

using namespace std::string_literals;

/*
Description:    A Header only templated functions to convert basic types to and from std::string
Author:         Yashar A. Rezaei
Date:           15.02.2022
*/

namespace convert
{

    template <typename T_return, typename T_arg>
    T_return to(T_arg value) = delete;

    template <>
    inline std::string to(bool value)
    {
        return (value ? std::string("1") : std::string("0"));
    };

    template <>
    inline bool to(std::string const &value)
    {
        if (value.compare("1"s))
            return true;
        else if (value.compare("0"s))
            return false;
        else if (value.compare("true"s) || value.compare("True"s) || value.compare("TRUE"s))
            return true;
        else if (value.compare("false"s) || value.compare("False"s) || value.compare("FALSE"s))
            return false;
        else
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
    };

    template <>
    inline bool to(char const *value)
    {
        if (std::strcmp(value, "1") == 0)
            return true;
        else if (std::strcmp(value, "0") == 0)
            return false;
        else if (std::strcmp(value, "true") == 0 || std::strcmp(value, "True") == 0 || std::strcmp(value, "TRUE") == 0)
            return true;
        else if (std::strcmp(value, "false") == 0 || std::strcmp(value, "False") == 0 || std::strcmp(value, "FALSE") == 0)
            return false;
        else
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
    };

    // Specialization from numerical to std::string
    template <>
    inline std::string to(std::int16_t value)
    {
        return std::to_string(static_cast<std::int32_t>(value));
    };

    template <>
    inline std::string to(std::int32_t value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(long long value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(std::int64_t value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(std::uint16_t value)
    {
        return std::to_string(static_cast<std::uint32_t>(value));
    };

    template <>
    inline std::string to(std::uint32_t value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(unsigned long long value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(std::uint64_t value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(float value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(double value)
    {
        return std::to_string(value);
    };

    template <>
    inline std::string to(long double value)
    {
        return std::to_string(value);
    };

    // Specialization from std::string const& to numerical
    template <>
    inline std::int32_t to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoi(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an int!");
        return num;
    };

    template <>
    inline std::int64_t to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoll(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long long!");
        return num;
    };

    template <>
    inline std::uint32_t to(std::string const &value)
    {
        std::size_t pos{};
        unsigned long numl = stoul(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned int!");
        auto num = static_cast<std::uint32_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return num;
    };

    template <>
    inline std::uint64_t to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoull(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value +
                                        "\" doesn't represent an unsigned long long!");
        return num;
    };

    template <>
    inline float to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stof(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a float!");
        return num;
    };

    template <>
    inline double to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stod(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a double!");
        return num;
    };

    template <>
    inline long double to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stold(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long double!");
        return num;
    };

    // Specialization from std::string to numerical
    template <>
    inline bool to(std::string value)
    {
        switch (value.size())
        {
        case 1:
            if (value == "1")
                return true;
            else if (value == "0")
                return false;
            else
                throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
        case 4:
            if (value == "True" || value == "TRUE" || value == "true")
                return true;
            else
                throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
        case 5:
            if (value == "False" || value == "FALSE" || value == "FALSE")
                return false;
            else
                throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
        default:
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
        }
    };

    template <>
    inline std::int16_t to(std::string value)
    {
        std::size_t pos{};
        auto numi = stoi(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a short!");
        auto num = static_cast<std::int16_t>(numi);
        if (num != numi)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return num;
    };

    template <>
    inline std::int32_t to(std::string value)
    {
        std::size_t pos{};
        auto num = stoi(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an int!");
        return num;
    };

    template <>
    inline std::int64_t to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoll(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long long!");
        return num;
    };

    template <>
    inline std::uint16_t to(std::string value)
    {
        std::size_t pos{};
        auto numl = stoul(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a unsigned short!");
        auto num = static_cast<std::uint16_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return num;
    };

    template <>
    inline std::uint32_t to(std::string value)
    {
        std::size_t pos{};
        auto numl = stoul(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned int!");
        auto num = static_cast<std::uint32_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return num;
    };

    template <>
    inline std::uint64_t to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoull(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value +
                                        "\" doesn't represent an unsigned long long!");
        return num;
    };

    template <>
    inline float to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stof(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a float!");
        return num;
    };

    template <>
    inline double to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stod(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a double!");
        return num;
    };

    template <>
    inline long double to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stold(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long double!");
        return num;
    };
} // namespace convert

#endif /* F829904E_F0F8_4832_98A1_1E614847C8E0 */
