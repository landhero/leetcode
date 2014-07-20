/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *);
};
RandomListNode * Solution::copyRandomList(RandomListNode * head){
    if (head==NULL)
        return head;
    RandomListNode * itr = head;
    while (itr != NULL){ //copy the node behind the origin node
        RandomListNode * next = itr->next;
        RandomListNode * node = new RandomListNode(itr->label);
        itr->next = node;
        node->next = next;
        itr = next;
    }
    itr = head;
    while (itr!=NULL){ //set the random pointer
        if (itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
    RandomListNode * rltHead = head->next;
    itr = head;
    while (itr!=NULL){
        RandomListNode * next = itr->next->next;
        itr->next->next = next==NULL? NULL:next->next;
        itr->next = next;
        itr = next;
    }
    return rltHead;
}
