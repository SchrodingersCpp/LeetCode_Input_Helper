#ifndef TREENODE_FUNCS_H
#define TREENODE_FUNCS_H

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include "num_string_funcs.h"
#include "treenode.h"

// Populates a vector with TreeNode string values.
template <typename T>
void PopulateVectorTree(
    const TreeNode<T>* root,
    std::vector<std::vector<std::string>>& vec_lvl,
    std::size_t curr_lvl=0, std::size_t curr_idx=0) {
  std::string str_val{ Number2String(root->val) };
  // Index at level coords.
  std::size_t lvl_curr_idx{
      curr_idx - static_cast<std::size_t>(std::pow(2.0, curr_lvl - 1) * 2 - 1) };
  vec_lvl[curr_lvl][lvl_curr_idx] = str_val;
  ++curr_lvl;  // Children are on the next level.
  curr_idx = (curr_idx + 1) * 2 - 1;  // Left child index.
  if (root->left) {
    PopulateVectorTree(root->left, vec_lvl, curr_lvl, curr_idx);
  }
  ++curr_idx;  // Right child index.
  if (root->right) {
    PopulateVectorTree(root->right, vec_lvl, curr_lvl, curr_idx);
  }
}

// Finds the longest string value.
std::size_t LongestStrVal(
    const std::vector<std::vector<std::string>>& vec_lvl) {
  std::size_t len_max{};
  for (const std::vector<std::string>& lvl_row : vec_lvl) {
    for (const std::string& str_val : lvl_row) {
      len_max = std::max(len_max, str_val.size());
    }
  }
  return len_max;
}

// Formats vector TreeNode string values.
void FormatTreeNodeStrVals(
    std::vector<std::vector<std::string>>& vec_lvl, const std::size_t width) {
  for (std::vector<std::string>& lvl_row : vec_lvl) {
    for (std::string& str_val : lvl_row) {
      CenterStr(str_val, width);
    }
  }
}

// Fills a vector containing each levels' formatted string values.
template <typename T>
std::vector<std::vector<std::string>> LevelValues(
    const TreeNode<T>* root, const std::size_t max_depth) {
  std::vector<std::vector<std::string>> vec_lvl(max_depth);
  for (std::size_t i{}; i < max_depth; ++i) {
    // Number of elements on current level.
    std::size_t n_lvl_elems{ static_cast<std::size_t>(std::pow(2.0, i)) };
    vec_lvl[i] = std::vector<std::string>(n_lvl_elems);
  }
  PopulateVectorTree(root, vec_lvl);
  std::size_t width{ LongestStrVal(vec_lvl) };
  FormatTreeNodeStrVals(vec_lvl, width);
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

// Replaces spaces with branch chars.
void GrowInitBranches(std::vector<std::vector<std::string>>& vec_lvl) {
  for (std::size_t i_lvl{}; i_lvl < (vec_lvl.size() - 1); ++i_lvl) {
    for (std::string& str_val : vec_lvl[i_lvl]) {
      if (!IsCenteredStrEmpty(str_val)) {
        std::replace(str_val.begin(), str_val.end(), ' ', '_');
      }
    }
  }
}

// Builds a vector with formatted the TreeNode levels.
std::vector<std::string> FormatTreeNodeLvls(
    const std::vector<std::vector<std::string>>& vec_lvl,
    const std::size_t min_dist=1) {
  std::vector<std::string> vec_fmt_lvl(vec_lvl.size());
  std::size_t dist_btw_elems{ min_dist };
  std::size_t dist_to_l_elem{};
  std::size_t n_branch{};
  
  return vec_fmt_lvl;
}

// Prints TreeNode.
template <typename T>
void PrintTreeNode(const TreeNode<T>* root) {
  std::size_t max_depth{ FindTreeNodeMaxDepth(root) };
  std::vector<std::vector<std::string>> vec_lvl{ LevelValues(root, max_depth) };
  GrowInitBranches(vec_lvl);
  std::vector<std::string> vec_fmt_lvl{ FormatTreeNodeLvls(vec_lvl) };
  for (const std::vector<std::string>& lvl_row : vec_lvl) {
    for (const std::string& str_val : lvl_row) {
      std::cout << '|' << str_val << '|' << ' ';
    }
    std::cout << '\n';
  }
}

#endif  // TREENODE_FUNCS_H
