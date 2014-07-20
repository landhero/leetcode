/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (head == NULL || head->next == NULL)
			return head;
		ListNode * itr =head->next;
		head->next = NULL;
		while (itr != NULL){
			ListNode * node = head, * last =NULL;
			ListNode *next = itr->next;
			while ((node != NULL) && (node->val < itr->val)){
				last = node;
				node = node->next;
			}
			itr->next = node;
			if (node == head)
				head = itr;
			else
				last->next = itr;
			itr = next;
		}
		return head;
	}
};
