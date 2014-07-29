/**
 * @author Hansheng Zhang
 */

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if (k<=1 || head == NULL)
      return head;
    ListNode * itr =head;
    ListNode * lastTail = NULL;
    while (itr != NULL){
      ListNode * nextItr = NULL;
      ListNode * curHead = NULL, *curTail =NULL;
      for (int i=0; i<k && itr!=NULL; i++){
        nextItr = itr->next;
        if (i==0)
          curHead = itr;
        if (i==k-1)
          curTail = itr;
        itr = nextItr;
      }
      if (curTail != NULL){
        ListNode * tmp = curHead->next, *last=curHead;
        for (int j=0; j<k-1; j++){
          ListNode * nextTmp = tmp->next;
          tmp->next = last;
          last = tmp;
          tmp = nextTmp;
        }
        if (curHead == head)
          head = curTail;
        if (lastTail != NULL)
          lastTail->next = curTail;
        lastTail = curHead;
        lastTail->next = NULL;
      }
      else {
        if (lastTail!=NULL)
          lastTail->next = curHead;
        break;
      }
    }
    return head;
  }
};
