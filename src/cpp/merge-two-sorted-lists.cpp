/**
 * @author Hansheng Zhang
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;
        ListNode * head=NULL, *curNode,*lastNode;
        while (!(l1==NULL || l2==NULL)){
            if (l1->val <= l2->val){
                curNode = l1;
                l1 = l1->next;
            }
            else {
                curNode = l2;
                l2 = l2->next;
            }
            if (head==NULL)
                head = curNode;
            else 
                lastNode->next = curNode;
            lastNode = curNode;
        }
        if (l2!=NULL)
            lastNode->next = l2;
        if (l1!=NULL)
            lastNode->next = l1;
        return head;
    }
};