#ifndef TREENODE_FUNCS_H
#define TREENODE_FUNCS_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "num_string_funcs.h"
#include "treenode.h"

// Fills a vector containing each levels' formatted string values.
template <typename T>
std::vector<std::vector<std::string>> LevelValues(
    const TreeNode<T>* root, const std::size_t max_depth) {
  std::vector<std::vector<std::string>> vec_lvl(max_depth);
  for (std::size_t i{}; i < max_depth; ++i) {
    // Number of elements on current level.
    std::size_t n_lvl_elems{ static_cast<std::size_t>(std::pow(2.0, i - 1.0)) };
    vec_lvl[i] = std::vector<std::string>(n_lvl_elems);
  }
  
  // TODO: Implement values filling.
  
  return vec_lvl;
}

// Finds TreeNode max depth.
template <typename T>
std::size_t FindTreeNodeMaxDepth(
    const TreeNode<T>* root, const std::size_t curr_d=1, std::size_t max_d=0) {
  max_d = std::max(curr_d, max_d);
  if (root->left) {
    max_d = FindTreeNodeMaxDepth(root->left, curr_d+1, max_d);
  }
  if (root->right) {
    max_d = FindTreeNodeMaxDepth(root->right, curr_d+1, max_d);
  }
  return max_d;
}

// Prints TreeNode.
template <typename T>
void PrintTreeNode(const TreeNode<T>* root) {
  std::size_t max_depth{ FindTreeNodeMaxDepth(root) };
  std::vector<std::vector<std::string>> vec_lvl{ LevelValues(root, max_depth) };
  
}

#endif  // TREENODE_FUNCS_H
