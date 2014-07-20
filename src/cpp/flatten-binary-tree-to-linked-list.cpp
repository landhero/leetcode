/*
just be careful: dfs is in-place?
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
  TreeNode * getLastNode(TreeNode *root){
    if (root == NULL)
      return NULL;
    TreeNode * left = root->left, *right = root->right;
    root->left = NULL;
    root->right = NULL;
    TreeNode * link = root;
    if (left !=NULL){
      root->right = left;
      link = getLastNode(left);
    }
    if (right != NULL){
      link->right = right;
      link = getLastNode(right);
    }
    return link;
  }
  void flatten(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    getLastNode(root);
  }
};
