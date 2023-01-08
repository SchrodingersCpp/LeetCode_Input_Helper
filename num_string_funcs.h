#ifndef NUM_STRING_FUNCS_H
#define NUM_STRING_FUNCS_H

#include <cstddef>
#include <iomanip>
#include <ios>
#include <sstream>
#include <string>

// Centers a string.
void CenterStr(std::string& str, const std::size_t width);

// Checks if a centered string value is empty.
// Since the value is centered, it's enough to check only 2 mid chars.
bool IsCenteredStrEmpty(const std::string& str);

// Converts a number to string.
template <typename T>
std::string Number2String(const T num, const int prec=10) {
  std::ostringstream oss_num;
  oss_num << std::fixed << std::setprecision(prec) << num;
  std::string str_num{ oss_num.str() };
  // Pointer to last char.
  const char* ptr{ str_num.data() + str_num.size() - 1 };
  // Remove decimal zeros only.
  if (str_num.find('.') != std::string::npos) {
    // Strips trailing zeros and decimal point (if it is last char).
    while (*ptr == '0') { --ptr; }
    if (*ptr == '.') { --ptr; }
  }
  str_num.resize(ptr - str_num.data() + 1);
  return str_num;
}

#endif  // NUM_STRING_FUNCS_H
