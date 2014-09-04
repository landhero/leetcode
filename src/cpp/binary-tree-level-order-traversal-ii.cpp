/**
 * Binary Tree Level Order Traversal II 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * Solution: easy, just be careful
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root);
};

void search(vector<TreeNode*> & nodes, vector<vector<int> > & rlt){
	vector<TreeNode*> next_nodes;
	for (auto node:nodes){
		if (node->left != NULL)
			next_nodes.push_back(node->left);
		if (node->right != NULL)
			next_nodes.push_back(node->right);
	}
	if (next_nodes.size()>0)
		search(next_nodes, rlt);
	vector<int> vc;
	for (auto node:nodes)
		vc.push_back(node->val);
	if (vc.size()>0)
		rlt.push_back(vc);
}

vector<vector<int> > Solution::levelOrderBottom(TreeNode * root){
	vector<vector<int> > rlt;
	if (root == NULL)
		return rlt;
	vector<TreeNode*> tmp(1, root);
	search(tmp, rlt);
	return rlt;
}
