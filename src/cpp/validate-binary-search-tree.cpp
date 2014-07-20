/**
 * add range to check
 * @author Hansheng Zhang (http://zhanghs.com)
 */

class Solution {
public:
    bool isValidBST(TreeNode *);
    bool isValidBST(TreeNode *, int, int);
};
bool Solution::isValidBST(TreeNode * root, int start, int end){
    if (root==NULL)
        return true;
    if (start <= root->val && end >= root->val)
        return isValidBST(root->left, start, root->val - 1) && isValidBST(root->right, root->val + 1, end);
    return false;
}
bool Solution::isValidBST(TreeNode * root){
    return isValidBST(root, INT_MIN, INT_MAX);
}
