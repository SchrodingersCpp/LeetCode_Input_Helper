#ifndef TXT_TO_VECVEC_H
#define TXT_TO_VECVEC_H

#include <string>
#include <vector>

#include "matrix_string.h"

// Converts a text vector-vector input to a vector-vector object.
template <typename T>
std::vector<std::vector<T>> Txt2VecVec(
    const std::string& txt_mtx,
    const char row_end=']', const char col_delim=',') {
  const std::vector<std::vector<std::string>> txt_vecvec{
      Txt2VecVecStr(txt_mtx, row_end, col_delim) };
  
}

#endif  // TXT_TO_VECVEC_H
