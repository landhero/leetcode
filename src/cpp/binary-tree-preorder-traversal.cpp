/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    void preOr(TreeNode * node, vector<int> & rlt){
        if (node==NULL)
        return;
        rlt.push_back(node->val);
        preOr(node->left,rlt);
        preOr(node->right,rlt);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> rlt;
        preOr(root, rlt);
        return rlt;
    }
};