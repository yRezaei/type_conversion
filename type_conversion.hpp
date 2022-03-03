#ifndef C554D4CB_CDE3_44BE_A2B1_01A549A3C733
#define C554D4CB_CDE3_44BE_A2B1_01A549A3C733

#include <cstdlib>
#include <string>
#include <stdexcept>

namespace convert
{
    template <typename T_return, typename T_arg>
    T_return to(T_arg value) = delete;

    // Numerical specialization to std::string
    template <>
    inline std::string to(int value) { return std::to_string(value); };

    template <>
    inline std::string to(long value) { return std::to_string(value); };

    template <>
    inline std::string to(long long value) { return std::to_string(value); };

    template <>
    inline std::string to(unsigned int value) { return std::to_string(value); };

    template <>
    inline std::string to(unsigned long value) { return std::to_string(value); };

    template <>
    inline std::string to(unsigned long long value) { return std::to_string(value); };

    template <>
    inline std::string to(float value) { return std::to_string(value); };

    template <>
    inline std::string to(double value) { return std::to_string(value); };

    template <>
    inline std::string to(long double value) { return std::to_string(value); };

    // std::string const& specialization to numerical
    template <>
    inline int to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoi(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an int!");
        return num;
    };

    template <>
    inline long to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stol(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a long!");
    };

    template <>
    inline long long to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoll(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a long long!");
        return num;
    };

    template <>
    inline unsigned int to(std::string const &value)
    {
        std::size_t pos{};
        unsigned long numl = stoul(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an unsigned int!");
        auto num = static_cast<unsigned int>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return num;
    };

    template <>
    inline unsigned long to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoul(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an unsigned long!");
        return num;
    };

    template <>
    inline unsigned long long to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stoull(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an unsigned long long!");
        return num;
    };

    template <>
    inline float to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stof(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a float!");
        return num;
    };

    template <>
    inline double to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stod(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a double!");
        return num;
    };

    template <>
    inline long double to(std::string const &value)
    {
        std::size_t pos{};
        auto num = std::stold(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a long double!");
        return num;
    };

    // std::string specialization to numerical
    template <>
    inline int to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoi(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an int!");
        return num;
    };

    template <>
    inline long to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stol(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a long!");
    };

    template <>
    inline long long to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoll(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a long long!");
        return num;
    };

    template <>
    inline unsigned int to(std::string value)
    {
        std::size_t pos{};
        unsigned long numl = stoul(value, &pos, 10);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an unsigned int!");
        auto num = static_cast<unsigned int>(numl);
        if (num != numl)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return num;
    };

    template <>
    inline unsigned long to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoul(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an unsigned long!");
        return num;
    };

    template <>
    inline unsigned long long to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stoull(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend an unsigned long long!");
        return num;
    };

    template <>
    inline float to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stof(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a float!");
        return num;
    };

    template <>
    inline double to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stod(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a double!");
        return num;
    };

    template <>
    inline long double to(std::string value)
    {
        std::size_t pos{};
        auto num = std::stold(value, &pos);
        if (value.size() != pos)
            throw std::invalid_argument("Te given string doesn't represend a long double!");
        return num;
    };
}

#endif /* C554D4CB_CDE3_44BE_A2B1_01A549A3C733 */
