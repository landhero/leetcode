/** 
* try to solve it with constant space and O(nlogn) using bottom up merge-sort
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
	ListNode *sortList(ListNode*);
	ListNode * mergeList(ListNode *, ListNode*, ListNode*, ListNode*, ListNode * &);
};
ListNode *Solution::sortList(ListNode *head) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if (head == NULL || head->next == NULL)
		return head;
	int n = 0;
	for (ListNode * itr = head; itr != NULL; itr = itr->next)
		n++; //caculate the num of nodes
	for (int width = 1; width<n; width += width){
		ListNode * lhead = head, *rhead = NULL, *ltail = NULL, *rtail = NULL, *last = NULL;
		while (true){
			if (lhead == NULL)
				break;
			ltail = lhead;
			for (int i = 1; i<width && ltail->next != NULL; i++)
				ltail = ltail->next;
			rhead = ltail->next;
			if (rhead == NULL)
				break;
			rtail = rhead;
			for (int i = 1; i<width && rtail->next != NULL; i++)
				rtail = rtail->next;
			ListNode* next = rtail->next;
			ListNode * mergetail = rtail;
			ListNode * rlt = mergeList(lhead, ltail, rhead, rtail, mergetail);
			if (last != NULL)
				last->next = rlt;
			mergetail->next = next;
			last = mergetail;
			if (lhead == head)
				head = rlt;
			lhead = next;
		}
	}
	return head;
}
ListNode * Solution::mergeList(ListNode * lhead, ListNode*ltail, ListNode* rhead, ListNode* rtail, ListNode * & mergeTail){
	ListNode * llast = NULL, *rlast = ltail;
	ListNode * ritr = rhead, *litr = lhead;
	while (ritr != NULL){
		ListNode * rnext = ritr == rtail ? NULL : ritr->next;
		while (litr != NULL){
			ListNode * lnext = litr == ltail ? NULL : litr->next;
			if (litr->val <= ritr->val){
				llast = litr;
				litr = lnext;
			}
			else break;
		}
		if (litr == NULL) //indicates all is sorted
			break;
		rlast->next = ritr->next;
		if (llast == NULL){
			ritr->next = lhead;
			lhead = ritr;
			llast = ritr;
		}
		else {
			llast->next = ritr;
			ritr->next = litr;
			llast = ritr;
		}
		ritr = rnext;
	}
	if (litr != NULL)
		mergeTail = ltail;
	return lhead;
}
