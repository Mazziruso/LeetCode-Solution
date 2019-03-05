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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;

        vector<int> res;
        int maxNum = 0x80000000;
        int levelNum;

        if(root == NULL) {
            return res;
        }

        q.push(root);
        while(!q.empty()){
            levelNum = q.size();
            for(int i=0; i<levelNum; i++) {
                if(q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
                maxNum = (maxNum < q.front()->val) ? q.front()->val : maxNum;
            }
            res.push_back(maxNum);
            maxNum = 0x80000000;
        }
        return res;
    }
};