#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void bST(TreeNode* node,int arr[],int &index) {
    if (!node) return;
    bST(node->left, arr, index);
    arr[index++] = node->val;
    bST(node->right, arr, index);
}
int main() {

    TreeNode* head = new TreeNode(7);
    head->left = new TreeNode(5);
    head->right = new TreeNode(9);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(6);
    head->right->left = new TreeNode(8);
    head->right->right = new TreeNode(10);
    int n = 7;
    int arr[n];
    int index = 0;
    bST(head,arr,index);
    cout << "Enter the value of k:";
    int k;
    cin >> k;
    cout << "The " << k << "th smallest element in the BST is: " << arr[k-1] << endl;
    cout << "the " << k << "th largest element in the BST is: " << arr[n-k] << endl;
    return 0;
}