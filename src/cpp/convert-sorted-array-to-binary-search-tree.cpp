/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
  typedef vector<int>::iterator vi;
  TreeNode *sortedArrayToBST(vi begin, vi end){
    if (begin==end)
      return NULL;
    vi middle = begin + (end-begin)/2;
    TreeNode * root  = new TreeNode(*middle);
    root->left = sortedArrayToBST(begin,middle);
    root->right = sortedArrayToBST(middle+1,end);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (num.empty())
      return NULL;
    return sortedArrayToBST(num.begin(),num.end());
  }
};