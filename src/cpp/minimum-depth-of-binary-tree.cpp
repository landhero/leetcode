/*
@author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    void minDepth(TreeNode * node, int & minDep, int curDepth){
        if (curDepth>=minDep)
            return;
        if (node==NULL)
            return;
        if (node->left==NULL && node->right==NULL){
            minDep = curDepth;
        }
        if (node->left != NULL)
            minDepth(node->left, minDep, curDepth+1);
        if (node->right != NULL)
            minDepth(node->right, minDep, curDepth+1);
    }
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root==NULL)
            return 0;
        int minDep = INT_MAX;
        minDepth(root, minDep, 1); 
        return minDep;
    }
};