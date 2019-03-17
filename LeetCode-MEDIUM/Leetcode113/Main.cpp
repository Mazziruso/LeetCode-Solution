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
    vector<int> path;
    vector<vector<int>> res;
    void DFS(TreeNode *root, int sum) {
        if(root == NULL) {
            return;
        }
        path.push_back(root->val);
        partSum += root->val;
        if(root->left == NULL && root->right == NULL) {
            if(partSum == sum) {
                res.push_back(path);
            }
        } else {
            DFS(root->left, sum);
            DFS(root->right, sum);
        }
        partSum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        partSum = 0;
        DFS(root, sum);
        return res;
    }
};