#ifndef TXT_TO_TREENODE_H
#define TXT_TO_TREENODE_H

#include <cstddef>
#include <string>
#include <tuple>
#include <vector>

#include "treenode.h"

// Converts text vector values to a type elements vector and
// boolean vector (nullptr or not).
template <typename T>
std::tuple<std::vector<T>, std::vector<bool>> VecValues(
    const std::vector<std::string>& txt_vec,
    const std::string null_str=std::string("null"));

// Finds left child indices of each element.
template <typename T>
std::vector<std::size_t> FindLeftChildIndex(
    const std::vector<T>& vec_elems, const std::vector<bool>& vec_valid);

// Builds a tree.
template <typename T>
TreeNode<T>* BuildTree(
    const std::vector<T>& vec_elems, const std::vector<bool>& vec_valid,
    const std::vector<std::size_t>& vec_lch_idx, const std::size_t curr_idx=0);

// Converts a text TreeNode input to a TreeNode object.
template <typename T>
TreeNode<T>* Txt2TreeNode(const std::string& txt_list);

#endif  // TXT_TO_TREENODE_H