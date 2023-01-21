#ifndef TXT_TO_VECVEC_H
#define TXT_TO_VECVEC_H

#include <cstddef>
#include <string>
#include <vector>

#include "matrix_string.h"
#include "txt_to_treenode.h"

// Converts a text vector-vector input to a vector-vector object.
template <typename T>
std::vector<std::vector<T>> Txt2VecVec(
    const std::string& txt_mtx,
    const char row_end=']', const char col_delim=',') {
  const std::vector<std::vector<std::string>> txt_vecvec{
      Txt2VecVecStr(txt_mtx, row_end, col_delim) };
  const std::size_t n_rows{ txt_vecvec.size() };
  std::vector<std::vector<T>> vecvec(n_rows);
  for (std::size_t i{}; i < n_rows; ++i) {
    auto [vec_elems, vec_valid] = VecValues<T>(txt_vecvec[i]);
    vecvec[i] = vec_elems;
  }
  return vecvec;
}

#endif  // TXT_TO_VECVEC_H
