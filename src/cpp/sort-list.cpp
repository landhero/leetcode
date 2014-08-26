/**
* Sort List
* Sort a linked list in O(n log n) time using constant space complexity.
* Solution: Bottom-up merge-sort
*/

class Solution {
public:
    ListNode *sortList(ListNode *head);
	ListNode *mergeList(ListNode*, ListNode*, ListNode*&);
};

ListNode *Solution::sortList(ListNode *head){
	if (head==NULL || head->next==NULL)
		return head;
	int n = 0;
	for (ListNode* itr = head; itr!=NULL; itr = itr->next) n++;
	for (int width=1; width<n; width+=width){
		ListNode * lhead = head, *last=NULL;
		while(lhead != NULL){
			ListNode * ltail = lhead;
			for (int i=1; i<width && ltail->next!=NULL; i++) ltail = ltail->next;
			if (ltail->next==NULL){
			    last->next = lhead;
				break;
			}
			ListNode * rhead = ltail->next;
			ltail->next = NULL;
			ListNode * rtail = rhead;
			for (int i=1; i<width && rtail->next!=NULL; i++) rtail = rtail->next;
			ListNode * next = rtail->next;
			rtail->next = NULL;
			ListNode* merged_tail = NULL;
			ListNode* merged_head = mergeList(lhead, rhead, merged_tail);
			if (last==NULL)
				head = merged_head;
			else last->next = merged_head;
			last = merged_tail;
			lhead = next;
		}
	}
	return head;
}

ListNode * Solution::mergeList(ListNode* lhead, ListNode* rhead, ListNode*& merged_tail){
	ListNode dummy_head(0);
	ListNode * last = &dummy_head;
	while (rhead != NULL){
		if (lhead!=NULL && lhead->val<rhead->val){
			merged_tail = lhead;
			lhead = lhead->next;
		}
		else {
			merged_tail = rhead;
			rhead = rhead->next;
		}
		last->next = merged_tail;
		last = merged_tail;
	}
	merged_tail->next = lhead;
	while (merged_tail->next != NULL)
		merged_tail = merged_tail->next;
	return dummy_head.next;
}
