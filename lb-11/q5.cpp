#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int>& a) {
    if (a.empty() || a[0] == -1) return NULL;
    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);
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
    return root;
}

void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

int findIndex(vector<int>& arr, int x) {
    for (int i = 0; i < (int)arr.size(); i++)
        if (arr[i] == x) return i;
    return -1;
}

int getNext(vector<int>& arr, int x) {
    int i = findIndex(arr, x);
    if (i == -1 || i + 1 >= (int)arr.size()) return INT_MIN;
    return arr[i + 1];
}

int getPrev(vector<int>& arr, int x) {
    int i = findIndex(arr, x);
    if (i <= 0) return INT_MIN;
    return arr[i - 1];
}

vector<int> getRange(vector<int>& arr, int L, int R) {
    vector<int> res;
    for (int v : arr)
        if (v >= L && v <= R) res.push_back(v);
    return res;
}

int getKth(vector<int>& arr, int k) {
    if (k < 1 || k > (int)arr.size()) return INT_MIN;
    return arr[k - 1];
}

int main() {
    vector<int> a = {40, 20, 60, 10, 30, 50, 70};
    vector<int> queries = {1, 3, 5, 8};
    int  k =5;
    Node* root = buildTree(a);

    vector<int> arr;
    inorder(root, arr);

    int nx = getNext(arr, 30);
    cout << nx << endl;

    int pv = getPrev(arr, 30);
    cout << pv << endl;

    vector<int> r = getRange(arr, 25, 60);
    cout << "RANGE = [";
    for (int i = 0; i < (int)r.size(); i++) {
        if (i) cout << ",";
        cout << r[i];
    }
    cout << "]" << endl;

    cout << "Kth = " << getKth(arr, k) << endl;

    return 0;
}