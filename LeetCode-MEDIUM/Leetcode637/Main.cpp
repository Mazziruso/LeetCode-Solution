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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;

        TreeNode *node;
        vector<double> res;
        double sum;
        int levelNum;

        if(root == NULL) {
            return res;
        }

        q.push(root);
        while(!q.empty()) {
            levelNum = q.size();
            sum = 0;
            for(int i=0; i<levelNum; i++) {
                if(q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                sum += q.front()->val;
                q.pop();
            }
            res.push_back(sum/levelNum);
        }
        return res;
    }
};