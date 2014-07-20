/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
};
UndirectedGraphNode * Solution::cloneGraph(UndirectedGraphNode *node){
    if (node == NULL)
        return NULL;
    unordered_map<int, UndirectedGraphNode*> labelNodeMap;
    UndirectedGraphNode * rlt = new UndirectedGraphNode(node->label);
    labelNodeMap[node->label] = rlt;
    stack<UndirectedGraphNode*> itrStack;
    itrStack.push(node);
    while (!itrStack.empty()){
        UndirectedGraphNode * itr = itrStack.top();
        itrStack.pop();
        UndirectedGraphNode * cloned = labelNodeMap[itr->label];
        for (auto nbr = (itr->neighbors).begin(); nbr!=(itr->neighbors).end(); nbr++){
            unordered_map<int, UndirectedGraphNode*>:: iterator i = labelNodeMap.find((*nbr)->label);
            UndirectedGraphNode * n = NULL;
            if (i==labelNodeMap.end()){
                n = new UndirectedGraphNode((*nbr)->label);
                itrStack.push(*nbr);
                labelNodeMap[n->label] = n;
            } else n = i->second;
            (cloned->neighbors).push_back(n);
        }
    }
    return rlt;
}