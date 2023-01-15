#include <string>

#include "treenode_funcs.h"
#include "treenode.h"
#include "txt_to_treenode.h"
#include "txt_to_vecvec.h"

void TreeNodeExample() {
  using T = int;
  const std::string txt_list{ "[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]" };
  TreeNode<T>* root{ Txt2TreeNode<T>(txt_list) };
  PrintTreeNode(root);
  DeleteTreeNode(root);
}

void VectorVectorExample() {
  using T = int;
  const std::string txt_mtx{ "[[1,1,0],[0,1,0],[0,1,0]]" };
  std::vector<std::vector<T>> vecvec{ Txt2VecVec<T>(txt_mtx) };
}

int main() {
  TreeNodeExample();
  VectorVectorExample();

  return 0;
}
