#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
struct TreeNode {
  T val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(T x) : val (x), left(nullptr), right(nullptr) {}
  TreeNode(T x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

#endif  // TREENODE_H
