/**
* @author Hansheng Zhang
*/

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n);
};

ListNode * Solution::removeNthFromEnd(ListNode * head, int n){
	ListNode dummy_head(0);
	dummy_head.next = head;
	ListNode * slow = &dummy_head, *fast = &dummy_head;
	while (n--)
		fast = fast->next;
	while (fast->next != NULL){
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;
	return dummy_head.next;
}
