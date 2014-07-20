/**
 * reference: http://www.bwscitech.com/a/jishuzixun/javayuyan/2013/0930/15822.html
 * space: O(lgn)--recursion depth; time: O(n)
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution{
public:
    TreeNode *sortedListToBST(ListNode *);
};
//after calling this function, curNode points to (curNode + len)
TreeNode *buildTreeWithLength(ListNode *&curNode, int len){
    if (len<=0)
        return NULL;
    int leftLen = (len-1)/2;
    TreeNode * leftNode = buildTreeWithLength(curNode, leftLen); // curNode -> root (mid)
    TreeNode * root = new TreeNode(curNode->val);
    root->left = leftNode;
    curNode = curNode->next;
    root->right = buildTreeWithLength(curNode, len-leftLen-1);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode * head){
    ListNode * itr = head;
    int len = 0;
    while (itr!=NULL){
        len++;
        itr = itr->next;
    }
    return buildTreeWithLength(head, len);
}