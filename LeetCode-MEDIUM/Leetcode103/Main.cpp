#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

struct qBase{
    TreeNode *node;
    int level;
    qBase() : node(NULL), level(0) {};
    qBase(TreeNode *n, int l) : node(n), level(l) {}; 
};

class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        deque<qBase> q;

        vector<int> vec;
        vector<vector<int>> res;
        qBase qb;
        int level = 0;
        bool direct = true;

        if(root == NULL) {
            return res;
        }

        q.push_back(qBase(root, 0));
        while(!q.empty()) {
            if(direct) {
                qb = q.front();
            } else {
                qb = q.back();
            }
            if(level != qb.level) {
                direct = ~direct;
                res.push_back(vec);
                vec.clear();
                level = qb.level;
            }
            if(direct) {
                qb = q.front();
                q.pop_front();
                vec.push_back(qb.node->val);
                if(qb.node->left != NULL) {
                    q.push_back(qBase(qb.node->left, level + 1));
                }
                if(qb.node->right != NULL) {
                    q.push_back(qBase(qb.node->right, level + 1));
                }
            } else {
                qb = q.back();
                q.pop_back();
                vec.push_back(qb.node->val);
                if(qb.node->right != NULL) {
                    q.push_front(qBase(qb.node->right, level + 1));
                }
                if(qb.node->left != NULL) {
                    q.push_front(qBase(qb.node->left, level + 1));
                }
            }
        }
        res.push_back(vec);
        return res;
    }
};