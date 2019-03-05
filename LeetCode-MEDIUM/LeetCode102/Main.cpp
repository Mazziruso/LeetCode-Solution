/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
struct qBase {
    TreeNode *node;
    int level;
    qBase() : node(NULL), level(0) {};
    qBase(TreeNode *n, int l) : node(n), level(l) {};
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {    
        queue<qBase> q;
        
        vector<vector<int>> res;
        vector<int> vec;
        qBase qb;
        int level = 0;
        
        //NULL TREE
        if(root == NULL) {
            return res;
        }
        
        q.push(qBase{root,0});
        while(!q.empty()) {
            qb = q.front();
            q.pop();
            if(level != qb.level) {
                res.push_back(vec);
                vec.clear();
                level = qb.level;
            }
            vec.push_back(qb.node->val);
            if(qb.node->left != NULL) {
                q.push(qBase{qb.node->left, level+1});
            }
            if(qb.node->right != NULL) {
                q.push(qBase(qb.node->right,level+1));
            }
        }
        res.push_back(vec);
        return res;
    }
};