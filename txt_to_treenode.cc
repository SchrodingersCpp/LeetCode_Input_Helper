#include "txt_to_treenode.h"

#include <cstddef>
#include <cstdlib>
#include <string>
#include <tuple>
#include <vector>

#include "treenode.h"
#include "vector_string.h"

template <typename T>
std::tuple<std::vector<T>, std::vector<bool>> VecValues(
    const std::vector<std::string>& txt_vec,
    const std::string null_str/*=std::string("null")*/) {
  std::vector<T> vec_elems(txt_vec.size());  // Values.
  std::vector<bool> vec_valid(txt_vec.size(), true);  // Is element valid?
  T null_elem{ 0 };  // A substitute value for nullptr.
  for (std::size_t i{}; i < txt_vec.size(); ++i) {
    if (txt_vec[i] == null_str) {
      vec_elems[i] = null_elem;
      vec_valid[i] = false;
    } else {
      vec_elems[i] = static_cast<T>(std::strtold(txt_vec[i].data(), nullptr));
    }
  }
  return { vec_elems, vec_valid };
}

template <typename T>
std::vector<std::size_t> FindLeftChildIndex(
    const std::vector<T>& vec_elems, const std::vector<bool>& vec_valid) {
  std::size_t n_elems{ vec_elems.size() };
  std::vector<std::size_t> vec_lch_idx(n_elems);
  std::size_t idx_lch{ 1 };
  for (std::size_t i{}; i < n_elems; ++i) {
    if (vec_valid[i]) {
      vec_lch_idx[i] = idx_lch;
      idx_lch += 2;
      if (idx_lch >= n_elems)
      { break; }
    }
  }
  return vec_lch_idx;
}

template <typename T>
TreeNode<T>* BuildTree(
    const std::vector<T>& vec_elems, const std::vector<bool>& vec_valid,
    const std::vector<std::size_t>& vec_lch_idx,
    const std::size_t curr_idx/*=0*/) {
  TreeNode<T>* root{ new TreeNode<T>(vec_elems[curr_idx]) };
  std::size_t idx_ch{ vec_lch_idx[curr_idx] };
  if (vec_valid[idx_ch]) {  // Left child.
    root->left = BuildTree<T>(vec_elems, vec_valid, vec_lch_idx, idx_ch);
  }
  if (vec_valid[++idx_ch]) {  // Right child.
    root->right = BuildTree<T>(vec_elems, vec_valid, vec_lch_idx, idx_ch);
  }
  return root;
}

template <typename T>
TreeNode<T>* Txt2TreeNode(const std::string& txt_list) {
  std::vector<std::string> txt_vec{ Txt2VecStr(txt_list) };
  auto [vec_elems, vec_valid] = VecValues<T>(txt_vec);
  std::vector<std::size_t> vec_lch_idx{ FindLeftChildIndex(vec_elems, vec_valid) };
  TreeNode<T>* root{ BuildTree<T>(vec_elems, vec_valid, vec_lch_idx) };
  return root;
}