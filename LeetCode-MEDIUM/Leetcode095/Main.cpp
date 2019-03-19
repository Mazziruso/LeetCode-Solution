#include <iostream>
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
    vector<TreeNode*> DFS(int s, int e) {
        if(s>e) {
            return vector<TreeNode*>();
        }
        if(s==e) {
            return vector<TreeNode*>({new TreeNode(s)});
        }
        vector<TreeNode*> res;
        vector<TreeNode*> lchild;
        vector<TreeNode*> rchild;
        for(int i=s; i<=e; i++) {
            lchild = DFS(s, i-1);
            rchild = DFS(i+1, e);
            if(rchild.empty()) {
                for(auto tl : lchild) {
                    TreeNode *root = new TreeNode(i);
                    root->left = tl;
                    res.push_back(root);
                }
            } else if(lchild.empty()) {
                for(auto tr : rchild) {
                    TreeNode *root = new TreeNode(i);
                    root->right = tr;
                    res.push_back(root);
                }
            } else {
                for(auto tl : lchild) {
                    for(auto tr : rchild) {
                        TreeNode *root = new TreeNode(i);
                        root->left = tl;
                        root->right = tr;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return DFS(1,n);
    }
};

int main() {

    vector<TreeNode*> res = Solution().generateTrees(3);

    return 0;
}