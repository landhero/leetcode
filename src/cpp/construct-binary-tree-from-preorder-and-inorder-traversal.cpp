/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    TreeNode * buildTree(vector<int>::iterator inBegin, vector<int>::iterator inEnd, 
                        vector<int>::iterator preBegin, vector<int>::iterator preEnd){
        int val = *(preBegin);
        TreeNode * root = new TreeNode(val);
        vector<int>::iterator ii, jj;
        for (ii=inBegin, jj=preBegin+1; ii!=inEnd && *ii!=val; ii++, jj++);
        if (ii!=inBegin)
            root->left = buildTree(inBegin, ii, preBegin+1, jj);
        if (ii+1 != inEnd)
            root->right = buildTree(ii+1, inEnd, jj, preEnd);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty())
            return NULL;
        return buildTree(inorder.begin(),inorder.end(),preorder.begin(), preorder.end());
    }
};