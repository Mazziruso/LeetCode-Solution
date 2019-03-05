#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    map<int, int> InIndex;
    vector<int> pre;

    TreeNode* construct(int preS, int preE, int inS, int inE) {
        if(preS > preE) {
            return NULL;
        }
        if(preS == preE) {
            return new struct TreeNode(pre[preS]);
        }
        int index = InIndex.find(pre[preS])->second;
        TreeNode *node = new struct TreeNode(pre[preS]);
        if(index == inS) { //Left SubTree
            node->right = construct(preS+1, preE, inS+1, inE);
        } else if(index == inE) {
            node->left = construct(preS+1, preE, inS, inE-1);
        } else {
            node->left = construct(preS+1, preS+index-inS, inS, index-1);
            node->right = construct(preS+index-inS+1, preE, index+1, inE);
        }
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            InIndex[inorder[i]] = i;
        }
        pre = preorder;
        return construct(0, preorder.size()-1, 0, inorder.size()-1);
    }
};