#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    vector<TreeNode*> path;
    TreeNode *p;
    TreeNode *q;
    void DFS(TreeNode *root) {
        if(root != NULL) {
            path.push_back(root);
            if(root == p) {
                pathP = path;
            }
            if(root == q) {
                pathQ = path;
            }
            DFS(root->left);
            DFS(root->right);
            path.pop_back();
        }
    }
    TreeNode* LCA() {
        int len = min(pathP.size(), pathQ.size());
        int i = 0;
        for(; i<len; i++) {
            if(pathP[i] != pathQ[i]) {
                break;
            }
        }
        return pathP[i-1];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        DFS(root);
        return LCA();
    }
};