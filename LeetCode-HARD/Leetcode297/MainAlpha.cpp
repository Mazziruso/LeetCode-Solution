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
		string str;
		queue<TreeNode*> q;
		TreeNode  *node;
		q.push(root);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			if (node == NULL) {
				str += "n ";
			}
			else {
				str += to_string(node->val);
				str += " ";
				q.push(node->left);
				q.push(node->right);
			}
		}
		return str;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		TreeNode *root = NULL;
		int len = data.size();
		int cnt = 0;
		string str[50000];
		
		int lindex = 0;
		int index = 0;
		while (lindex < len) {
			index = data.find_first_of(" ", lindex);
			str[cnt++] = data.substr(lindex, index - lindex);
			lindex = index + 1;
		}
		
		if (cnt == 0 || str[0] == "n") {
			return NULL;
		}
		
		queue<TreeNode*> q;
		root = new TreeNode(stoi(str[0]));
		q.push(root);
		TreeNode *parent;
		for (int i = 1; i < cnt; i++) {
			parent = q.front();
			q.pop();
			if (str[i] != "n") {
				parent->left = new TreeNode(stoi(str[i]));
				q.push(parent->left);
			}
			i++;
			if (str[i] != "n") {
				parent->right = new TreeNode(stoi(str[i]));
				q.push(parent->right);
			}
		}
		return root;
	}
};

int main() {

	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(4);
	root->right->left->left = new TreeNode(3);
	root->right->left->right = new TreeNode(1);

	Codec s;

	string str = s.serialize(root);
	root = s.deserialize(str);

	system("pause");
	return 0;
}
