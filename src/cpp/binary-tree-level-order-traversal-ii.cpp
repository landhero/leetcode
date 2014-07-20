/**
  * @author Hansheng Zhang (http://zhanghs.com)
  */
 class Solution {
 public:
     vector<vector<int> > levelOrderBottom(TreeNode *root) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
       vector<vector<int>> rlt;
       if (root == NULL)
         return rlt;
       queue<TreeNode*> vt;
       vector<int> vi;
       vt.push(root);
       vt.push(NULL);
       TreeNode * node;
       while(!vt.empty()){
         node = vt.front();
         if (node==NULL){
           if (vi.size()>0){
             rlt.push_back(vi);
             vi = vector<int>();
             vt.push(NULL);
           }
         }
         else{
           vi.push_back(node->val);
           if (node->left != NULL)
             vt.push(node->left);
           if (node->right != NULL)
             vt.push(node->right);
         }
         vt.pop();
       }
       vector<vector<int>> real_rlt;
       vector<vector<int>>::iterator vii;
       for (vii=rlt.end()-1; vii+1 != rlt.begin(); vii--){
         real_rlt.push_back(*vii);
       }
       return real_rlt;
     }
 };