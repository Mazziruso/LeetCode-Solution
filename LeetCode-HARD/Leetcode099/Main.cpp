#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
	TreeNode *loc1;
	TreeNode *loc2;
	TreeNode *prev;
	void recoverTree(TreeNode *root) {
		loc1 = NULL;
		loc2 = NULL;
		prev = new TreeNode(INT_MIN);
		inOrder(root);
		swap(loc1->val, loc2->val);
	}
	void inOrder(TreeNode *root) {
		if (root != NULL) {
			inOrder(root->left);
			if (root->val < prev->val) {
				if (loc1 == NULL) {
					loc1 = prev;
				}
				else {
					loc2 = root;
				}
			}
			prev = root;
			inOrder(root->right);
		}
	}
};

int main() {

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(2);

	Solution s;
	s.recoverTree(root);

	system("pause");
	return 0;
}