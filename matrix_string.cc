#include "matrix_string.h"

#include <cstddef>
#include <string>
#include <vector>

#include "vector_string.h"


#include <iostream>



std::size_t CountRows(
    const std::string& txt_mtx, const char row_end/*=']'*/) {
  std::size_t n_rows{};
  for (std::size_t i{ 1 }; i < (txt_mtx.size() - 1); ++i) {
    if (txt_mtx[i] == row_end) { ++n_rows; }
  }
  return n_rows;
}

void FillRows(
    std::vector<std::vector<std::string>>& txt_vecvec,
    const std::string& txt_mtx,
    const char row_end/*=']'*/, const char col_delim/*=','*/) {
  const std::size_t n_rows{ txt_vecvec.size() };
  std::size_t idx_beg{ 1 };
  std::size_t n_row{};
  std::size_t len{};
  for (std::size_t i{ idx_beg }; i < (txt_mtx.size() - 1); ++i) {
    if (txt_mtx[i] == row_end) {
      len = i - idx_beg + 1;
      txt_vecvec[n_row++] = Txt2VecStr(txt_mtx.substr(idx_beg, len), col_delim);
      idx_beg = i + 1;
    }
  }
}

std::vector<std::vector<std::string>> Txt2VecVecStr(
    const std::string& txt_mtx,
    const char row_end/*=']'*/, const char col_delim/*=','*/) {
  const std::size_t n_rows{ CountRows(txt_mtx, row_end) };
  std::vector<std::vector<std::string>> txt_vecvec(n_rows);
  FillRows(txt_vecvec, txt_mtx, row_end, col_delim);
  
  std::cout << n_rows << '\n';
  return txt_vecvec;
}
