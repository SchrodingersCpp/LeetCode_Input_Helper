#ifndef MATRIX_FUNCS_H
#define MATRIX_FUNCS_H

#include <iostream>
#include <vector>

// Print a matrix.
template <typename T>
void PrintVecVec(const std::vector<std::vector<T>>& vecvec) {
  for (auto& row : vecvec) {
    std::cout << '\t';
    for (auto& elem : row) {
      std::cout << elem << '\t';
    }
    std::cout << '\n';
  }
}

#endif  // MATRIX_FUNCS_H
