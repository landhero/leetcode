/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (p==NULL && q==NULL)
            return true;
        if (p==NULL || q==NULL)
            return false;
        if (p->val == q->val)
            return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
        return false;
    }
};