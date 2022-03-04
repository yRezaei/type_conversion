#ifndef F829904E_F0F8_4832_98A1_1E614847C8E0
#define F829904E_F0F8_4832_98A1_1E614847C8E0

#include <cstdlib>
#include <string>
#include <stdexcept>
#include <exception>
#include <utility>

/*
Description:    A Header only templated functions to convert basic types to and from std::string
Author:         Yashar Abbasalizadeh Rezaei
Email:          yashar.rezaei@atlascopco.com
*/
namespace convert {
template <typename T_return, typename T_arg>
T_return to(T_arg value) = delete;

// Numerical specialization to std::string
template <>
inline std::string to(std::int16_t value) {
  return std::to_string(static_cast<std::int32_t>(value));
};

template <>
inline std::string to(std::int32_t value) {
  return std::to_string(value);
};

template <>
inline std::string to(long value) {
  return std::to_string(value);
};

template <>
inline std::string to(std::in64_t value) {
  return std::to_string(value);
};

template <>
inline std::string to(std::uint16_t value) {
  return std::to_string(static_cast<std::uint32_t>(value));
};

template <>
inline std::string to(std::uint32_t value) {
  return std::to_string(value);
};

template <>
inline std::string to(unsigned long value) {
  return std::to_string(value);
};

template <>
inline std::string to(std::uint64_t value) {
  return std::to_string(value);
};

template <>
inline std::string to(float value) {
  return std::to_string(value);
};

template <>
inline std::string to(double value) {
  return std::to_string(value);
};

template <>
inline std::string to(long double value) {
  return std::to_string(value);
};

// std::string const& specialization to numerical
template <>
inline bool to(std::string const& value) {
  return (value.size() > 1 ? (value == "True" || value == "TRUE" || value == "true" ? true : false)
                           : (value == "1" ? true : false));
};

template <>
inline std::int32_t to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stoi(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an int!");
  return num;
};

template <>
inline long to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stol(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long!");
  return num;
};

template <>
inline std::uint64_t to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stoll(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long long!");
  return num;
};

template <>
inline std::uint32_t to(std::string const& value) {
  std::size_t pos{};
  unsigned long numl = stoul(value, &pos, 10);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned int!");
  auto num = static_cast<std::uint32_t>(numl);
  if (num != numl) throw std::out_of_range("The given string can not be converted to unsigned int.");
  return num;
};

template <>
inline unsigned long to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stoul(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned long!");
  return num;
};

template <>
inline std::uint64_t to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stoull(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value +
                                "\" doesn't represent an unsigned long long!");
  return num;
};

template <>
inline float to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stof(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a float!");
  return num;
};

template <>
inline double to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stod(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a double!");
  return num;
};

template <>
inline long double to(std::string const& value) {
  std::size_t pos{};
  auto num = std::stold(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long double!");
  return num;
};

// std::string specialization to numerical
template <>
inline bool to(std::string value) {
  return (value.size() > 1 ? (value == "True" || value == "TRUE" || value == "true" ? true : false)
                           : (value == "1" ? true : false));
};

template <>
inline std::int32_t to(std::string value) {
  std::size_t pos{};
  auto num = std::stoi(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an int!");
  return num;
};

template <>
inline long to(std::string value) {
  std::size_t pos{};
  auto num = std::stol(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long!");
  return num;
};

template <>
inline std::int64_t to(std::string value) {
  std::size_t pos{};
  auto num = std::stoll(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long long!");
  return num;
};

template <>
inline std::uint32_t to(std::string value) {
  std::size_t pos{};
  unsigned long numl = stoul(value, &pos, 10);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned int!");
  auto num = static_cast<std::uint32_t>(numl);
  if (num != numl) throw std::out_of_range("The given string can not be converted to unsigned int.");
  return num;
};

template <>
inline unsigned long to(std::string value) {
  std::size_t pos{};
  auto num = std::stoul(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent an unsigned long!");
  return num;
};

template <>
inline std::uint64_t to(std::string value) {
  std::size_t pos{};
  auto num = std::stoull(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value +
                                "\" doesn't represent an unsigned long long!");
  return num;
};

template <>
inline float to(std::string value) {
  std::size_t pos{};
  auto num = std::stof(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a float!");
  return num;
};

template <>
inline double to(std::string value) {
  std::size_t pos{};
  auto num = std::stod(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a double!");
  return num;
};

template <>
inline long double to(std::string value) {
  std::size_t pos{};
  auto num = std::stold(value, &pos);
  if (value.size() != pos)
    throw std::invalid_argument(std::string("The given string \"") + value + "\" doesn't represent a long double!");
  return num;
};
}  // namespace convert

#endif /* F829904E_F0F8_4832_98A1_1E614847C8E0 */
