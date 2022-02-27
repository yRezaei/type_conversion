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
    inline int to(std::string const &value) { return std::stoi(value); };

    template <>
    inline long to(std::string const &value) { return std::stol(value); };

    template <>
    inline long long to(std::string const &value) { return std::stoll(value); };

    template <>
    inline unsigned int to(std::string const &value)
    {
        unsigned long lresult = stoul(value, 0, 10);
        unsigned int result = lresult;
        if (result != lresult)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return result;
    };

    template <>
    inline unsigned long to(std::string const &value) { return std::stoul(value); };

    template <>
    inline unsigned long long to(std::string const &value) { return std::stoull(value); };

    template <>
    inline float to(std::string const &value) { return std::stof(value); };

    template <>
    inline double to(std::string const &value) { return std::stod(value); };

    template <>
    inline long double to(std::string const &value) { return std::stold(value); };

    // std::string specialization to numerical
    template <>
    inline int to(std::string value) { return std::stoi(value); };

    template <>
    inline long to(std::string value) { return std::stol(value); };

    template <>
    inline long long to(std::string value) { return std::stoll(value); };

    template <>
    inline unsigned int to(std::string value)
    {
        unsigned long lresult = stoul(value, 0, 10);
        unsigned int result = lresult;
        if (result != lresult)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return result;
    };

    template <>
    inline unsigned long to(std::string value) { return std::stoul(value); };

    template <>
    inline unsigned long long to(std::string value) { return std::stoull(value); };

    template <>
    inline float to(std::string value) { return std::stof(value); };

    template <>
    inline double to(std::string value) { return std::stod(value); };

    template <>
    inline long double to(std::string value) { return std::stold(value); };

    // char const* specialization to numerical
    template <>
    inline int to(char const* value) { return std::stoi(value); };

    template <>
    inline long to(char const* value) { return std::stol(value); };

    template <>
    inline long long to(char const* value) { return std::stoll(value); };

    template <>
    inline unsigned int to(char const* value)
    {
        unsigned long lresult = std::stoul(value, 0, 10);
        unsigned int result = lresult;
        if (result != lresult)
            throw std::out_of_range("The given string can not be converted to unsigned int.");
        return result;
    };

    template <>
    inline unsigned long to(char const* value) { return std::stoul(value); };

    template <>
    inline unsigned long long to(char const* value) { return std::stoull(value); };

    template <>
    inline float to(char const* value) { return std::stof(value); };

    template <>
    inline double to(char const* value) { return std::stod(value); };

    template <>
    inline long double to(char const* value) { return std::stold(value); };
}

#endif /* C554D4CB_CDE3_44BE_A2B1_01A549A3C733 */
