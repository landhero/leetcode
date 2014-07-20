/*
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    void getResult (TreeNode * node, vector<vector<int>> & rlt, int target, vector<int> & curPath){
        target -= node->val;
        vector<int> path = curPath;
        path.push_back(node->val);
        if (node->left==NULL && node->right==NULL && target==0){
            rlt.push_back(path);
            return;
        }
        if (node->left!=NULL)
            getResult(node->left, rlt, target, path);
        if (node->right!=NULL)
            getResult(node->right, rlt, target, path);
        return;
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > rlt;
        if (root==NULL)
            return rlt;
        vector<int> path;
        getResult(root, rlt, sum, path);
        return rlt;
    }
};