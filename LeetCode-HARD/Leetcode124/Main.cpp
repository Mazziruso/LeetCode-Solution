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
	int maxPathSum(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int singleSum;
		int maxSum = pathSum(root, singleSum);
		return maxSum;
	}

	int pathSum(TreeNode *node, int &singleSum) {
		if (node == NULL) {
			singleSum = 0;
			return INT_MIN;
		}

		int leftSum;
		int rightSum;
		int maxLeft = pathSum(node->left, leftSum);
		int maxRight = pathSum(node->right, rightSum);

		singleSum = node->val + max(leftSum, rightSum);
		singleSum = (singleSum < 0) ? 0 : singleSum;

		int tmp = leftSum + rightSum + node->val;
		if (tmp > max(maxLeft, maxRight)) {
			return tmp;
		}
		else {
			return max(maxLeft, maxRight);
		}
	}
};

int main() {

	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(-1);

	Solution s;

	printf("%d\n", s.maxPathSum(root));

	system("pause");
	return 0;
}