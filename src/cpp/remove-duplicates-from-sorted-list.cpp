/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode * tmp = head;
        while (tmp!=NULL && tmp->next !=NULL){
            if (tmp->val == (tmp->next)->val)
                tmp->next = (tmp->next)->next;
            else tmp = tmp->next;
        }
        return head;
    }
};