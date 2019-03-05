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

struct qBase {
    TreeNode *node;
    int level;
    qBase(TreeNode *n, int l) : node(n), level(l) {};
    qBase() : node(NULL), level(0) {};
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<qBase> q;

        vector<int> vec;
        vector<vector<int>> res;
        vector<vector<int>> res_tmp;
        qBase qb;
        int level = 0;

        if(root == NULL) {
            return res;
        }

        q.push(qBase(root, 0));
        while(!q.empty()) {
            qb = q.front();
            q.pop();
            if(level != qb.level) {
                res_tmp.push_back(vec);
                vec.clear();
                level = qb.level;
            }
            vec.push_back(qb.node->val);
            if(qb.node->left != NULL) {
                q.push(qBase(qb.node->left, level+1));
            }
            if(qb.node->right != NULL) {
                q.push(qBase(qb.node->right, level+1));
            }
        }
        res.push_back(vec);
        for(int i=res_tmp.size()-1; i>=0; i--){
            res.push_back(res_tmp[i]);
        }
        return res;
    }
};