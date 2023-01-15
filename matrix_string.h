#ifndef MATRIX_STRING_H
#define MATRIX_STRING_H

#include <cstddef>
#include <string>
#include <vector>

// Counts number of rows in a text vector-vector.
std::size_t CountRows(
    const std::string& txt_mtx, const char row_end=']');

// Fills vector rows.
void FillRows(
    std::vector<std::vector<std::string>>& txt_vecvec,
    const std::string& txt_mtx,
    const char row_end=']', const char col_delim=',');

// Converts a text list to a text vector-vector.
std::vector<std::vector<std::string>> Txt2VecVecStr(
    const std::string& txt_mtx,
    const char row_end=']', const char col_delim=',');

#endif  // MATRIX_STRING_H
