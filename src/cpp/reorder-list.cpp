/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    void reorderList(ListNode *);
    ListNode * reverseList(ListNode *);
};

ListNode * Solution::reverseList(ListNode * head){
    if (head==NULL || head->next==NULL)
        return head;
    ListNode * last = head, *itr = head->next;
    head->next = NULL;
    while (itr != NULL){
        ListNode * next = itr->next;
        itr->next = last;
        last = itr;
        itr = next;
    }
    return last;
}
void Solution::reorderList(ListNode * head){
    if (head==NULL || head->next == NULL)
        return;
    ListNode * ltail = head;
    ListNode * itr = head->next;
    while (itr!=NULL && itr->next!=NULL){
        ltail = ltail->next;
        itr = (itr->next)->next;
    }
    ListNode * rhead = reverseList(ltail->next);
    ltail->next = NULL;
    ListNode * litr = head;
    ListNode * ritr = rhead;
    while (litr!=NULL){
        ListNode * nextItr = litr->next;
        if (ritr!=NULL){
            ListNode * nextRitr = ritr->next;
            litr->next = ritr;
            ritr->next = nextItr;
            ritr = nextRitr;
        }
        litr = nextItr;
    }
}
