#include <string>

#include "treenode.h"
#include "txt_to_treenode.h"

int main() {
  using T = int;
  const std::string txt_list{ "[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]" };
  
  TreeNode<T>* root{ Txt2TreeNode<T>(txt_list) };

  return 0;
}
