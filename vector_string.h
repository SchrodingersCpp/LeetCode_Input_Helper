#ifndef VECTOR_STRING_H
#define VECTOR_STRING_H

#include <cstddef>
#include <string>
#include <vector>

// Counts number of elements in a text list.
std::size_t CountElements(const std::string& txt_list, const char delim=',');

// Converts a text list to a text vector.
std::vector<std::string> Txt2VecStr(
    const std::string& txt_list, const char delim=',');

#endif  // VECTOR_STRING_H