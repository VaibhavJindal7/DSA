#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <functional>

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
public:
    vector<int> closestKValues(Node* root, double target, int k) {
        function<bool(int, int)> comp = [target](int a, int b) {
            double diffA = abs(a - target);
            double diffB = abs(b - target);
            
            if (diffA == diffB) {
                return a < b; 
            }
            return diffA < diffB; 
        };
        
        priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);
        
        inorder(root, target, k, maxHeap);

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        sort(result.begin(), result.end(), [target](int a, int b) {
            double diffA = abs(a - target);
            double diffB = abs(b - target);
            if (diffA == diffB) return a < b;
            return diffA < diffB;
        });
        
        return result;
    }

private:
    void inorder(Node* node, double target, int k, priority_queue<int, vector<int>, function<bool(int, int)>>& maxHeap) {
        if (!node) return;
        
        inorder(node->left, target, k, maxHeap);
        double currentDiff = abs(node->data - target);
        
        if (maxHeap.size() < k) {
            maxHeap.push(node->data);
        } else {
            int worstVal = maxHeap.top();
            double worstDiff = abs(worstVal - target);

            if (currentDiff < worstDiff || (currentDiff == worstDiff && node->data < worstVal)) {
                maxHeap.pop();
                maxHeap.push(node->data);
            }
        }

        
        inorder(node->right, target, k, maxHeap);
    }
};

int main() {

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    double target = 3.8;
    int k = 2;

    vector<int> closest = sol.closestKValues(root, target, k);

    cout << "Closest " << k << " values to " << target << " are: ";
    for (int val : closest) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}