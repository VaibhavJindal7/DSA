#include <iostream>
#include <algorithm>
#include <climits>
#include <vector> 

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int maxSum = 0;

    vector<int> solve(Node* root) {
        if (!root) {
            return {1, INT_MAX, INT_MIN, 0};
        }

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        if (left[0] == 1 && right[0] == 1 && root->data > left[2] && root->data < right[1]) {

            int currentSum = left[3] + right[3] + root->data;
            maxSum = max(maxSum, currentSum); 

            int minVal = min(root->data, left[1]);
            int maxVal = max(root->data, right[2]);

            return {1, minVal, maxVal, currentSum};
        }
        return {0, INT_MAX, INT_MIN, 0};
    }

public:
    int maxSumBST(Node* root) {
        maxSum = 0;
        solve(root);
        return maxSum;
    }
};

int main() {
   
    
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(1); 
    
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(10); 

    Solution sol;
    cout << "Maximum sum of a valid BST subtree: " << sol.maxSumBST(root) << endl;
    
    return 0;
}