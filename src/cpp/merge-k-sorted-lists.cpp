/**
 * @author Hansheng Zhang
 */
ListNode * merge2Lists(ListNode* list1, ListNode* list2){
  ListNode * rlt = NULL;
  ListNode * curNode = NULL;
  while (list1!=NULL || list2!=NULL){
    ListNode * lastNode = curNode;
    if (list1==NULL){
      curNode = list2;
      list2 = list2->next;
    }
    else if (list2==NULL){
      curNode = list1;
      list1=list1->next;
    }
    else if (list1->val <= list2->val){
      curNode = list1;
      list1 = list1->next;
    }
    else {
      curNode = list2;
      list2=list2->next;
    }
    if (rlt == NULL)
      rlt = curNode;
    else
      lastNode->next = curNode;
  }
  return rlt;
}

struct ListWithSize{
  int size;
  ListNode * list;
};

bool comp(ListWithSize a, ListWithSize b){
  return a.size > b.size;
}

class Solution {
public:
  int countSize(ListNode* list){
    int size = 0;
    while (list!=NULL){
      size++;
      list=list->next; 
    }
    return size;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int size = lists.size();
    if (size<=0)
      return NULL;
    ListWithSize * sizeList = new ListWithSize[size+1];
    for (int i=0; i<size; i++){
      sizeList[i].size = countSize(lists[i]);
      sizeList[i].list = lists[i];
    }
    make_heap(&sizeList[0], &sizeList[size], comp);
    for (int i = 1; i<size; i++){
      pop_heap(&sizeList[0], &sizeList[size-i+1], comp);
      ListWithSize l1 = sizeList[size-i];
      pop_heap(&sizeList[0], &sizeList[size-i],comp);
      ListWithSize l2 = sizeList[size-i-1];
      ListWithSize lr;
      lr.size = l1.size + l2.size;
      lr.list = merge2Lists(l1.list,l2.list);
      sizeList[size-i-1] = lr;
      push_heap(&sizeList[0], &sizeList[size-i], comp);
    }
    ListNode * rlt = sizeList[0].list;
    delete []sizeList;
    return rlt;
  }
};