#include <iostream>
#include <map>
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
    map<int, int> InIndex;
    vector<int> post;
    TreeNode* construct(int postS, int postE, int inS, int inE) {
        if(postS > postE) {
            return NULL;
        }
        if(postS == postE) {
            return new struct TreeNode(post[postE]);
        }
        int index = InIndex.find(post[postE])->second;
        TreeNode *node = new struct TreeNode(post[postE]);
        if(index == inS) { //Right SubTree
            node->right = construct(postS, postE-1, inS+1, inE);
        } else if(index == inE) { //Left SubTree
            node->left = construct(postS, postE-1, inS, inE-1);
        } else {
            node->left = construct(postS, postE-(inE-index+1),inS,index-1);
            node->right = construct(postE-(inE-index), postE-1, index+1, inE);
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++) {
            InIndex[inorder[i]] = i;
        }
        post = postorder;
        return construct(0, postorder.size()-1, 0, inorder.size()-1);
    }
};