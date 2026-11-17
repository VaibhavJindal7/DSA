#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    

    return (left->val == right->val) && 
           isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    head->right->left = new TreeNode(4);
    head->right->right = new TreeNode(3);

    if(head == nullptr) {
        cout << "The tree is empty and symmetric." << endl;
    } 
    if (isSymmetric(head->left, head->right)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}