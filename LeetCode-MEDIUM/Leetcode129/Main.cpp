#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum;
    void DFS(TreeNode *root, int number) {
        if(root == NULL) {
            return;
        }
        number = number * 10 + root->val;
        if(root->left==NULL && root->right==NULL) {
            sum += number;
        } else {
            DFS(root->left, number);
            DFS(root->right, number);
        }
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        DFS(root, 0);
        return sum;
    }
};