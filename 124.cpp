/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
int getMaxPath(TreeNode *p, TreeNode *f) {
	if (f->left != NULL && f->left->val > 0) {
		p->val += f->left->val;
	}
	if (f->right != NULL && f->right->val > 0) {
		p->val += f->right->val;
	}
	int max = p->val;
	if (p->left != NULL) {
		int leftMax = getMaxPath(p->left, f->left);
		if (leftMax > max)
			max = leftMax;
	}
	if (p->right != NULL) {
		int rightMax = getMaxPath(p->right, f->right);
		if (rightMax > max)
			max = rightMax;
	}
	return max;
}

TreeNode *getMaxSonPath(TreeNode *p) {
	TreeNode *node = new TreeNode(p->val);
	int max = 0;
	if (p->left != NULL) {
		node->left = getMaxSonPath(p->left);
		int leftPath = node->left->val;
		if (leftPath > max)
			max = leftPath;
	}
	if (p->right != NULL) {
		node->right = getMaxSonPath(p->right);
		int rightPath = node->right->val;
		if (rightPath > max)
			max = rightPath;
	}
	node->val += max;
	return node;
}

int maxPathSum(TreeNode* root) {
	TreeNode *froot = getMaxSonPath(root);
	return getMaxPath(root, froot);
}

};
