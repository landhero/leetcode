/**
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    TreeNode * buildTree(vector<int>::iterator inBegin, vector<int>::iterator inEnd, 
                        vector<int>::iterator postBegin, vector<int>::iterator postEnd){
        int val = *(postEnd-1);
        TreeNode * root = new TreeNode(val);
        vector<int>::iterator ii, jj;
        vector<int> leftIn, leftPost, rightIn, rightPost;
        for (ii=inBegin, jj=postBegin; ii!=inEnd && *ii!=val; ii++, jj++);
        if (ii!=inBegin)
            root->left = buildTree(inBegin, ii, postBegin, jj);
        if (ii+1 != inEnd)
            root->right = buildTree(ii+1, inEnd, jj, postEnd-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty())
            return NULL;
        return buildTree(inorder.begin(),inorder.end(),postorder.begin(), postorder.end());
    }
};