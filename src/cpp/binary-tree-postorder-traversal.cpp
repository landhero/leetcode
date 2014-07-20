/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    void postTra(TreeNode * node, vector<int>&rlt){
        if (node==NULL)
            return;
        postTra(node->left, rlt);
        postTra(node->right, rlt);
        rlt.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> rlt;
        postTra(root,rlt);
        return rlt;
    }
};
