#include "vector_string.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

std::size_t CountElements(
    const std::string& txt_list, const char delim/*=','*/) {
  return std::count(txt_list.begin(), txt_list.end(), delim) + 1;
}

std::vector<std::string> Txt2VecStr(
    const std::string& txt_list, const char delim/*=','*/) {
  const std::size_t n_elems{ CountElements(txt_list, delim) };
  std::vector<std::string> txt_vec(n_elems);
  std::size_t idx_vec{};
  // First index and length of an element in the text list.
  std::size_t idx_beg{ 1 };
  std::size_t len{};
  // First char (opening bracket) is skipped.
  for (std::size_t i{ idx_beg }; i < txt_list.size(); ++i) {
    if ( (txt_list[i] == delim) || (i == (txt_list.size() - 1)) ) {
      len = i - idx_beg;
      txt_vec[idx_vec++] = txt_list.substr(idx_beg, len);
      idx_beg = i + 1;
    }
  }
  return txt_vec;
}
