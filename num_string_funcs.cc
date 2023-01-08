#include "num_string_funcs.h"

#include <cstddef>
#include <string>

void CenterStr(std::string& str, const std::size_t width) {
  std::size_t str_len{ str.size() };
  if (str_len < width) {
    std::string centered(width, ' ');
    std::size_t n_left_spaces{ (width - str_len) / 2 };
    centered.replace(n_left_spaces, str_len, str);
    str = centered;
  }
}

bool IsCenteredStrEmpty(const std::string& str) {
  const std::size_t idx_mid{ str.size() / 2 };
  return (str[idx_mid] == ' ') && (str[str.size() - 1 - idx_mid] == ' ');
}
