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

struct qbase {
	TreeNode *node;
	int index;
	qbase() : node(NULL), index(0) {};
	qbase(TreeNode *n, int x) : node(n), index(x) {};
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		queue<qbase> q;
		qbase qb;
		TreeNode *node;
		string str;
		if (root == NULL) {
			return str;
		}
		q.push(qbase(root, -1));
		str += to_string(root->val);
		str += " -1 -1 ";
		int len = 0;
		while (!q.empty()) {
			qb = q.front();
			q.pop();
			node = qb.node;

			if (node->left != NULL) {
				str += to_string(node->left->val);
				str += " ";
				str += to_string(len);
				str += " 0 ";
				q.push(qbase(node->left, len));
			}
			if (node->right != NULL) {
				str += to_string(node->right->val);
				str += " ";
				str += to_string(len);
				str += " 1 ";
				q.push(qbase(node->right, len));
			}
			len++;
		}
		return str;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int child[1000][2];
		int keys[1000];
		int len = data.size();
		int cnt = 0;
		string str;
		int val;
		int kid;
		int lindex = 0;
		int index = 0;
		while (lindex < len) {
			child[cnt][0] = -1;
			child[cnt][1] = -1;
			index = data.find_first_of(" ", lindex);
			str = data.substr(lindex, index - lindex);
			lindex = index + 1;
			val = stoi(str);
			keys[cnt] = val;

			index = data.find_first_of(" ", lindex);
			str = data.substr(lindex, index - lindex);
			lindex = index + 1;
			val = stoi(str);

			index = data.find_first_of(" ", lindex);
			str = data.substr(lindex, index - lindex);
			lindex = index + 1;
			kid = stoi(str);
			if (val >= 0) {
				child[val][kid] = cnt;
			}
			cnt++;
		}

		if (cnt == 0) {
			return NULL;
		}

		TreeNode *root = new TreeNode(0);
		TreeNode *node;
		qbase qb;
		queue<qbase> q;
		q.push(qbase(root, 0));
		while (!q.empty()) {
			qb = q.front();
			q.pop();
			node = qb.node;
			node->val = keys[qb.index];
			if (child[qb.index][0] >= 0) {
				node->left = new TreeNode(0);
				q.push(qbase(node->left, child[qb.index][0]));
			}
			if (child[qb.index][1] >= 0) {
				node->right = new TreeNode(0);
				q.push(qbase(node->right, child[qb.index][1]));
			}
		}
		return root;
	}
};

int main() {

	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);

	Codec s;

	root = s.deserialize(s.serialize(root));

	system("pause");
	return 0;
}
