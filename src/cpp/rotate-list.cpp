/**
* @author Hansheng Zhang
*/
class Solution {
public:
    ListNode *rotateRight(ListNode*, int);
};

ListNode*  Solution::rotateRight(ListNode *head, int k){
    if (head==NULL || k<=0)
        return head;
    ListNode * left = head, *right = head, * rlt = head;
    int n = 0;
    while (right!=NULL && ++n)
        right = right->next;
    k = k % n;
    right = head;
    while (k--) right = right->next;
    while (right->next!=NULL){
        left = left->next;
        right = right->next;
    }
    if (left->next!=NULL){
        rlt = left->next;
        right->next = head;
        left->next = NULL;
    }
    return rlt;
}