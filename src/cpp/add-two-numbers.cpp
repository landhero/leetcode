/**
 * @author Hansheng Zhang
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * rlt = new ListNode(0);
        ListNode * tmp = rlt;
        while (tmp != NULL){
            if (l1!=NULL){
                tmp->val += l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL){
                tmp->val += l2->val;
                l2 = l2->next;
            }
            if (tmp->val >=10 || l1!=NULL || l2!=NULL ){
                tmp->next = new ListNode((tmp->val)/10);
                tmp->val = tmp->val %10;
            }
            tmp = tmp->next;
        }
        return rlt;
    }
};
