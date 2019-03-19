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
    TreeNode* DFS(TreeNode *root) {
        if(root!=NULL) {
            TreeNode *ptr = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *ptr1 = DFS(root->right);
            if(ptr1==NULL) {
                root->right = ptr;
                ptr1 = root;
            } else {
                ptr1->right = ptr;
            }
            TreeNode *ptr2 = DFS(ptr);
            return ptr2==NULL ? ptr1 : ptr2;
        }
        return NULL;
    }
    void flatten(TreeNode* root) {
        DFS(root);
    }
};

int main() {

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    Solution().flatten(root);

    return 0;
}