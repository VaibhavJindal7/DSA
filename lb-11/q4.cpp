#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

int main() {
    vector<int> a = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    vector<int> queries = {1, 3, 5, 8};

    Node* root = NULL;
    queue<Node*> q;
    if (!a.empty() && a[0] != -1) {
        root = new Node(a[0]);
        q.push(root);
    }

    int i = 1;
    while (!q.empty() && i < (int)a.size()) {
        Node* cur = q.front(); q.pop();
        if (i < (int)a.size() && a[i] != -1) {
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        i++;
        if (i < (int)a.size() && a[i] != -1) {
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        i++;
    }

    vector<int> sorted;
    inorder(root, sorted);

    cout << "[";
    for (int j = 0; j < (int)queries.size(); j++) {
        int k = queries[j];
        if (j) cout << ",";
        if (k < 1 || k > (int)sorted.size())
            cout << "INVALID";
        else
            cout << sorted[k - 1];
    }
    cout << "]" << endl;

    return 0;
}