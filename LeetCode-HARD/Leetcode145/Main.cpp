#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> seq;
		stack<TreeNode*> nodeS;
		stack<int> cntS;
		int cnt = 0;
		TreeNode *node = root;

		if (node == NULL) {
			return seq;
		}

		nodeS.push(node);
		cntS.push(cnt);
		while (!nodeS.empty()) {
			node = nodeS.top();
			cnt = cntS.top();
			cntS.pop();
			if (cnt == 2) {
				seq.push_back(node->val);
				nodeS.pop();
			}
			else if (cnt == 1) {
				if (node->right != NULL) {
					nodeS.push(node->right);
					cntS.push(cnt + 1);
					cntS.push(0);
				}
				else {
					cntS.push(cnt + 1);
				}
			}
			else {
				if (node->left != NULL) {
					nodeS.push(node->left);
					cntS.push(cnt + 1);
					cntS.push(0);
				}
				else {
					cntS.push(cnt + 1);
				}
			}
		}
		return seq;
	}
};

int main() {

	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);

	Solution s;

	vector<int> res = s.postorderTraversal(root);

	for (auto i : res) {
		printf("%d ", i);
	}
	printf("\n");

	system("pause");
	return 0;
}