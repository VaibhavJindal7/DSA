#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int depth(TreeNode* node) {
    if (node ==nullptr) return 0;
    if(node->left == nullptr && node->right == nullptr) return 0       ;
    if(node->left == nullptr) return 1 + depth(node->right);
    if(node->right == nullptr) return 1 + depth(node->left);
    return 1 + min(depth(node->left), depth(node->right));
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->right = new TreeNode(3);

    if(head == nullptr) {
        cout << "The tree is empty." << endl;
    } else {
        int treeDepth = depth(head);
        cout << "The minimum depth of the tree is: " << treeDepth << endl;
    }
    return 0;
}
