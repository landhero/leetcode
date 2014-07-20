/*
@author Hansheng Zhang
 */
class Solution {
public:
    bool isBalanced(const TreeNode * , int & depth);
    bool isBalanced(TreeNode *root) {
        int depth;
        return isBalanced(root, depth);
    }
};
bool Solution::isBalanced(const TreeNode * root, int & depth){
    depth = 0;
    if (root==NULL)
        return true;
    int lDep, rDep;
    bool rlt = isBalanced(root->left, lDep) && isBalanced(root->right, rDep);
    rlt = rlt && (abs(lDep-rDep)<=1);
    depth = max(lDep, rDep)+1;
    return rlt;
}
