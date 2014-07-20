/**
 * be careful
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    vector <TreeNode *> generateTrees(int min, int max){
        if (min>max){
            TreeNode * tmp = NULL;
            return vector<TreeNode*>(1,tmp);
        }
        vector<TreeNode *> rlt;
        for (int i=min; i<=max; i++){
            vector<TreeNode*> left_nodes = generateTrees(min, i-1);
            int lsize = left_nodes.size();
            vector<TreeNode*> right_nodes = generateTrees(i+1,max);
            int rsize = right_nodes.size();
            for (int j=0; j<lsize; j++)
                for (int k=0; k<rsize; k++){
                    TreeNode * node = new TreeNode(i);
                    node->left = left_nodes[j];
                    node->right = right_nodes[k];
                    rlt.push_back(node);
                }
        }
        return rlt;
    }
    vector<TreeNode *> generateTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return generateTrees(1,n);
    }
};