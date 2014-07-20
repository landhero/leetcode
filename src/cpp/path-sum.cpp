/*
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right ==NULL && root->val == sum)
            return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};
