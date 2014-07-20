/**
 * be careful
 * @author Hansheng Zhang (http://zhanghs.com)
 */

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if (n-m<1 || head==NULL)
      return head;
    int size = 0;
    ListNode* ltail =NULL;
    int i = 0;
    ListNode * itr = head, * last = NULL, *rhead;
    while (itr!=NULL){
      ListNode * next = itr->next;
      i++;
      if (i==m){
        ltail = last;
        rhead = itr;
      }
      if (i>m && i<=n){
        itr->next = last;
      }
      if (i==n){
        rhead->next = next;
        if (ltail!=NULL){
          ltail->next = itr;
          return head;
        }
        else return itr;
      }
      last = itr;
      itr = next;
    }
    return NULL;
  }
};

