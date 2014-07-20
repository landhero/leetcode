/*
just connect left child to right and right child to next->left
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root==NULL || root->left==NULL || root->right==NULL)
            return;
        root->left->next = root->right;
        if (root->next!=NULL)
            root->right->next=root->next->left;
        connect(root->left);
        connect(root->right);
    }
};