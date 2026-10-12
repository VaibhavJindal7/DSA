#include <bits/stdc++.h>
using namespace std;

class QueueArray {
    int* arr;
    int front, rear, capacity;

public:
    QueueArray(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};

struct Node {
    int data;
    Node* next;
};

class QueueList {
    Node* front;
    Node* rear;

public:
    QueueList() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node{x, nullptr};
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return val;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    cout << "Queue using Array :\n";
    QueueArray qa(5);
    qa.enqueue(10);
    qa.enqueue(20);
    qa.enqueue(30);
    cout << qa.dequeue() << endl;
    cout << qa.peek() << endl;

    cout << "Queue using Linked List :\n";
    QueueList ql;
    ql.enqueue(10);
    ql.enqueue(20);
    ql.enqueue(30);
    cout << ql.dequeue() << endl;
    cout << ql.peek() << endl;
}