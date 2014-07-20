/**
 * Pay much attention when using stack
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *);
};

vector<int> Solution::inorderTraversal(TreeNode * root){
    stack<TreeNode*> s;
    TreeNode *curNode = root;
    vector<int> rlt;
    while (curNode != NULL || !s.empty()){
        while (curNode != NULL){
            s.push(curNode);
            curNode = curNode->left;
        }
        if (!s.empty()){
            curNode = s.top();
            s.pop();
            rlt.push_back(curNode->val);
            curNode = curNode->right;
        }
    }
    return rlt;
}