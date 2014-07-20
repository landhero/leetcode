/*
process two kinds of values carefully
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int maxPathSum(TreeNode *root);
};
int getValue(TreeNode * node, int & connectedValue){
    connectedValue = INT_MIN;
    if (node==NULL)
        return INT_MIN;
    connectedValue = node->val;
    int connectedLeft, connectedRight;
    int leftMax = getValue(node->left, connectedLeft);
    int rightMax = getValue(node->right, connectedRight);
    int lrMax = max(connectedLeft,connectedRight);
    if (lrMax>0)
        connectedValue += lrMax;
    return max(max(leftMax, rightMax),node->val+max(0,connectedLeft)+max(0,connectedRight));
}
int Solution::maxPathSum(TreeNode * root){
    int tmp;
    return getValue(root, tmp);
}
