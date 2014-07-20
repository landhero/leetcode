/*
easy
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    void sumNumbers(TreeNode *node, int &totalSum, int curSum){
        curSum = curSum *10 + node->val;
        if (node->left==NULL && node->right==NULL){
            totalSum += curSum;
            return;
        }
        if (node->left != NULL)
            sumNumbers(node->left, totalSum, curSum);
        if (node->right != NULL)
            sumNumbers(node->right, totalSum, curSum);
    }
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root==NULL)
            return 0;
        int sum = 0;
        sumNumbers(root, sum, 0);
        return sum;
    }
};