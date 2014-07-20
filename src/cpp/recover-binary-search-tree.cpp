/**
 * Inorder morris traversal
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    void recoverTree(TreeNode *);
};
void Solution::recoverTree(TreeNode * root){
    TreeNode * prevNode = NULL, *node1 = NULL, *node2 = NULL;
    TreeNode * curNode = root;
    while (curNode != NULL){
        if (curNode->left==NULL){
            if (prevNode != NULL && prevNode->val > curNode->val)
                if (node1 == NULL){
                    node1 = prevNode;
                    node2 = curNode;
                }
                else {
                    node2 = curNode;
                }
            prevNode = curNode;
            curNode = curNode->right;
        }
        else{
            TreeNode * pre = curNode->left;
            while (pre->right != NULL && pre->right != curNode)
                pre=pre->right;
            if (pre->right==NULL){
                pre->right = curNode;
                curNode = curNode->left;
            }else{
                if (prevNode != NULL && prevNode->val > curNode->val)
                    if (node1 == NULL){
                        node1 = prevNode;
                        node2 = curNode;
                    }
                    else {
                        node2 = curNode;
                    }
                pre->right = NULL;
                prevNode = curNode;
                curNode = curNode->right;
            }
        }
    }
    swap(node1->val, node2->val);
}