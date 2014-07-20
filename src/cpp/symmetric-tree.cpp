/**
* iteratively: test each level & insert '#' to represents a null child
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    bool isSymmetric(TreeNode * left, TreeNode * right){
        if (left==NULL && right==NULL)
            return true;
        if (left==NULL || right==NULL)
            return false;
        if (left->val!=right->val)
            return false;
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root==NULL)
            return true;
        return isSymmetric(root->left,root->right);
    }
};
//iteratively
bool Solution::isSymmetric (TreeNode * root){
    if (root == NULL)
        return true;
    vector<TreeNode *> nodes;
    nodes.push_back(root);
    while (!nodes.empty()){
        int size = nodes.size();
        for (int i=0, j=size-1; i<j; i++, j--){
            if (nodes[i]==NULL && nodes[j]==NULL)
                continue;
            if (nodes[i]==NULL || nodes[j]==NULL || nodes[i]->val != nodes[j]->val)
                return false;
        }
        vector<TreeNode *> next;
        for (int i=0; i<size; i++)
            if (nodes[i]!=NULL){
                next.push_back(nodes[i]->left);
                next.push_back(nodes[i]->right);
            }
        nodes = next;
    }
    return true;
}

