
#include <iostream>
#include <queue>
#include <map>
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

void topView(Node* root) {
        if (root == nullptr) return;

        map<int, int> topNodes;

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->data;
            }
            if (node->left != nullptr) {
                q.push({node->left, hd - 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, hd + 1});
            }
        }

        for (auto const& pair : topNodes) {
            cout << pair.second << " ";
        }
        cout << endl;
    }

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Top View of the tree is: ";
    topView(root); 

    return 0;
}