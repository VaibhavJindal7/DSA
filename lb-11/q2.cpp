#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
    Node(int d) : data(d), left(nullptr), right(nullptr),
                  lthread(false), rthread(false) {}
};

void convert(Node* root) {
    Node *cur = root;
    Node *prev = nullptr;
    while (cur) {
        if (!cur->left) {
            cur->left = prev;
            cur->lthread = true;
            prev = cur;
            cur = cur->right;
        } else {
            Node* p = cur->left;
            while (p->right && p->right != cur) p = p->right;

            if (!p->right) {
                p->right = cur;
                cur = cur->left;
            } else {
                p->rthread = true;
                prev = cur;
                cur = cur->right;
            }
        }
    }
}

Node* leftmost(Node* n) {
    while (n && !n->lthread) n = n->left;
    return n;
}

void inorder(Node* root) {
    for (Node* c = leftmost(root); c; ) {
        cout << c->data << ' ';
        c = c->rthread ? c->right : leftmost(c->right);
    }
    cout << '\n';
}

int main() {
    Node* r = new Node(4);
    r->left  = new Node(2);
    r->right  = new Node(6);
    r->left->left  = new Node(1);
    r->left->right  = new Node(3);
    r->right->left = new Node(5);  
    r->right->right = new Node(7);

    convert(r);
    inorder(r);
}