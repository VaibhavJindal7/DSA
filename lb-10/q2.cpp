#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    Node* first = nullptr;
    Node* middle = nullptr;
    Node* last = nullptr;
    Node* prev = nullptr;

    void inorder(Node* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev != nullptr && root->data < prev->data) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } 
            else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(Node* root) {
        first = middle = last = prev = nullptr;
    
        inorder(root);
        if (first != nullptr && last != nullptr) {
            swap(first->data, last->data);
        } else if (first != nullptr && middle != nullptr) {
    
            swap(first->data, middle->data);
        }
    }
};

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    
    Node* root = new Node(4);
    root->left = new Node(6);      
    root->right = new Node(2);     
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Inorder traversal of the incorrect tree: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "Inorder traversal of the corrected BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}