/**
 * @author Hansheng Zhang
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode * last = NULL;
        ListNode * ite = head;
        ListNode * rlt = head;
        while ((ite != NULL) && (ite->next != NULL)){
            ListNode * a = ite;
            ListNode * b = ite->next;
            a->next  = b->next;
            b->next = a;
            if (last != NULL){
                last->next = b;
            }
            else {
                rlt = b;
            }
            last = a;
            ite  = last->next;
        }
        return rlt;
    }
};
