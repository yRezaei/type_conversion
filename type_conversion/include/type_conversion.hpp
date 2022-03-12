#ifndef F829904E_F0F8_4832_98A1_1E614847C8E0
#define F829904E_F0F8_4832_98A1_1E614847C8E0

#include <string>
#include <stdexcept>
#include <exception>
#include <utility>
#include <cstring>
#include <cerrno>
#include <cstdlib>

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

    // Boolean specialization
    template <>
    inline std::string to(bool value)
    {
        return (value ? std::string("1") : std::string("0"));
    };

    template <>
    inline bool to(std::string const &value)
    {
        if (value.compare("1"s) == 0)
            return true;
        else if (value.compare("0"s) == 0)
            return false;
        else if (value.compare("true"s) == 0 || value.compare("True"s) == 0 || value.compare("TRUE"s) == 0)
            return true;
        else if (value.compare("false"s) == 0 || value.compare("False"s) == 0 || value.compare("FALSE"s) == 0)
            return false;
        else
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent any known boolean representation!");
    };

    template <>
    inline bool to(std::string value)
    {
        if (value.compare("1"s) == 0)
            return true;
        else if (value.compare("0"s) == 0)
            return false;
        else if (value.compare("true"s) == 0 || value.compare("True"s) == 0 || value.compare("TRUE"s) == 0)
            return true;
        else if (value.compare("false"s) == 0 || value.compare("False"s) == 0 || value.compare("FALSE"s) == 0)
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
    inline std::int16_t to(std::string const &value)
    {
        std::size_t pos{};
        auto numl = stoi(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an std::int16_t!");
        auto num = static_cast<std::int16_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to std::int16_t.");
        return num;
    };

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
        auto num = std::stol(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long!");
        return num;
    };

    template <>
    inline long long to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoll(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long long!");
        return num;
    };

    template <>
    inline std::uint16_t to(std::string const &value)
    {
        std::size_t pos{};
        auto numl = stoul(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned short!");
        auto num = static_cast<std::uint16_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned short.");
        return num;
    };

    template <>
    inline std::uint32_t to(std::string const &value)
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
    inline std::uint64_t to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoul(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value +
                                        "\" doesn't represent an unsigned long!");
        return num;
    };

    template <>
    inline unsigned long long to(std::string const &value)
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

    // char const* to numerical
    template <>
    inline std::int16_t to(char const *value)
    {
        char *value_end;
        auto num = static_cast<std::int16_t>(std::strtol(value, &value_end, 10));
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known short representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline std::int32_t to(char const *value)
    {
        char *value_end;
        auto num = static_cast<std::int32_t>(std::strtol(value, &value_end, 10));
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known int representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline std::int64_t to(char const *value)
    {
        char *value_end;
        auto num = std::strtol(value, &value_end, 10);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known long representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline long long to(char const *value)
    {
        char *value_end;
        auto num = std::strtoll(value, &value_end, 10);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known long long representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline std::uint16_t to(char const *value)
    {
        char *value_end;
        auto num = static_cast<std::uint16_t>(std::strtoul(value, &value_end, 10));
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known unsigned short representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline std::uint32_t to(char const *value)
    {
        char *value_end;
        auto num = static_cast<std::uint32_t>(std::strtoul(value, &value_end, 10));
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known unsigned int representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline std::uint64_t to(char const *value)
    {
        char *value_end;
        auto num = std::strtoul(value, &value_end, 10);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known unsigned long representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline unsigned long long to(char const *value)
    {
        char *value_end;
        auto num = std::strtoull(value, &value_end, 10);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known unsigned long long representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline float to(char const *value)
    {
        char *value_end;
        auto num = std::strtof(value, &value_end);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known float representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline double to(char const *value)
    {
        char *value_end;
        auto num = std::strtod(value, &value_end);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known double representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    template <>
    inline long double to(char const *value)
    {
        char *value_end;
        auto num = std::strtold(value, &value_end);
        if (std::strlen(value) != static_cast<std::size_t>(value_end - value))
            throw std::invalid_argument(std::string("The given byte string \"") + value + "\" doesn't represent any known long double representation!");
        if (errno == ERANGE)
            throw std::out_of_range(std::string("The given string \"") + value + "\" doesn't represent a long double!");

        return num;
    }

    // Specialization from std::string to numerical
    template <>
    inline std::int16_t to(std::string value)
    {
        std::size_t pos{};
        auto numl = stoi(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an std::int16_t!");
        auto num = static_cast<std::int16_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to std::int16_t.");
        return num;
    };

    template <>
    inline std::int32_t to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoi(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an int!");
        return num;
    };

    template <>
    inline std::int64_t to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stol(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long!");
        return num;
    };

    template <>
    inline long long to(std::string value)
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
            throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned short!");
        auto num = static_cast<std::uint16_t>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned short.");
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
        auto num = std::stoul(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument(std::string("The given string \"") + value +
                                        "\" doesn't represent an unsigned long!");
        return num;
    };

    template <>
    inline unsigned long long to(std::string value)
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
