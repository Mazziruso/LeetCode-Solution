#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
	}
};

int main() {

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	Codec s;

	root = s.deserialize(s.serialize(root));

	system("pause");
	return 0;
}
