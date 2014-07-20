/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL)
            return head;
        ListNode * ltail = NULL;
        if (head->val < x)
            ltail = head;
        ListNode *itr = head->next, *last = head;
        while (itr != NULL){
            if (itr->val >= x){
                last = itr;
                itr = itr->next;
                continue;
            }
            if (last == ltail){
                ltail = itr;
                last = itr;
                itr = itr->next;
                continue;
            }
            last->next = itr->next;
            if (ltail==NULL){
                itr->next = head;
                head = itr;
            }
            else {
                itr->next = ltail->next;
                ltail->next = itr;
            }
            ltail = itr;
            itr = last->next;
        }
        return head;
    }
};