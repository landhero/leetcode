/*
similar to i: all you need to do is to be careful
@author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root==NULL)
            return;
        TreeLinkNode * rightSideNext = root->next;
        while (rightSideNext != NULL){
            if (rightSideNext->left != NULL){
                rightSideNext = rightSideNext->left;
                break;
            }
            if (rightSideNext->right != NULL){
                rightSideNext = rightSideNext->right;
                break;
            }
            rightSideNext = rightSideNext->next;
        }
        if (root->left != NULL){
            if (root->right !=NULL)
                root->left->next = root->right;
            else root->left->next = rightSideNext;
        }
        if (root->right!=NULL)
            root->right->next = rightSideNext;
        connect(root->right);
        connect(root->left);
    }
};