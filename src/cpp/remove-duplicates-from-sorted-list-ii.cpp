/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head==NULL)
	    return head;
	ListNode * curHead = head, *curTail = head, *lastTail=NULL;
	ListNode * itr = head->next;
	while (itr!=NULL){
	    ListNode * nextNode = itr->next;
	    if (itr->val == curTail->val)
		curTail = curTail->next;
	    else{
		if (curHead!=curTail){
		    if (curHead==head){
			head = itr;
		    }
		    else lastTail->next = itr;
		}
		else lastTail = curTail;
		curHead = curTail = itr;
	    }
	    itr = nextNode;
	}
	if (curHead != curTail){
	    if (curHead == head)
		return NULL;
	    else lastTail->next = NULL;
	}
	return head;
    }
};
