#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right, *parent;
    Node(int v) : val(v), left(NULL), right(NULL), parent(NULL) {}
};

Node* findNode(Node* root, int S) {
    if (!root) return NULL;
    if (root->val == S) return root;
    Node* l = findNode(root->left, S);
    if (l) return l;
    return findNode(root->right, S);
}

int main() {
    vector<int> a = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    int S = 5, K = 2;

    Node* root = NULL;
    queue<Node*> q;

    if (a[0] != -1) {
        root = new Node(a[0]);
        q.push(root);
    }

    int i = 1;
    while (!q.empty() && i < (int)a.size()) {
        Node* cur = q.front(); q.pop();
        if (i < (int)a.size() && a[i] != -1) {
            cur->left = new Node(a[i]);
            cur->left->parent = cur;
            q.push(cur->left);
        }
        i++;
        if (i < (int)a.size() && a[i] != -1) {
            cur->right = new Node(a[i]);
            cur->right->parent = cur;
            q.push(cur->right);
        }
        i++;
    }

    Node* target = findNode(root, S);

    queue<Node*> bq;
    unordered_set<Node*> vis;
    bq.push(target);
    vis.insert(target);

    int dist = 0;
    while (!bq.empty() && dist < K) {
        int sz = bq.size();
        while (sz--) {
            Node* n = bq.front(); bq.pop();
            Node* nb[3] = { n->left, n->right, n->parent };
            for (int j = 0; j < 3; j++) {
                Node* c = nb[j];
                if (c && !vis.count(c)) {
                    vis.insert(c);
                    bq.push(c);
                }
            }
        }
        dist++;
    }

    cout << "[";
    int first = 1;
    while (!bq.empty()) {
        if (!first) cout << ",";
        cout << bq.front()->val;
        first = 0;
        bq.pop();
    }
    cout << "]" << endl;
    return 0;
}