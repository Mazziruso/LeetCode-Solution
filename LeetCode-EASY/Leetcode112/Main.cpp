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
    int partSum;
    bool flag;
    void DFS(TreeNode *root, int sum) {
        if(root == NULL) {
            return;
        }
        partSum += root->val;
        if(root->left==NULL && root->right==NULL) {
            flag = (partSum == sum) ? true : flag;
        } else {
            DFS(root->left, sum);
            DFS(root->right, sum);
        }
        partSum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        flag = false;
        partSum = 0;
        DFS(root, sum);
        return flag;
    }
};