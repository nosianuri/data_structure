#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
class myStack {
public:
    int* arr;
    int top;
    int capacity;
    myStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    void clear() {
        delete[] arr;
    }
    void push(int value) {
        if (top < capacity - 1) {
            arr[++top] = value;
        }
    }
    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1; 
    }
    bool isEmpty() {
        return top == -1;
    }
};
class myQueue {
public:
    int* arr;
    int front;
    int rear;
    int capacity;
    myQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    void clear() {
        delete[] arr;
    }
    void enqueue(int value) {
        if (front == -1) {
            front = 0;
        }
        if (rear < capacity - 1) {
            arr[++rear] = value;
        }
    }
    int dequeue() {
        if (front <= rear) {
            return arr[front++];
        }
        return -1; 
    }
    bool isEmpty() {
        return front > rear;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    myStack stack(n);
    myQueue queue(m);
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        stack.push(value);
    }
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        queue.enqueue(value);
    }
    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.pop() != queue.dequeue()) {
            cout << "NO" << endl;
            queue.clear();
            return 0;
        }
    }
    if (stack.isEmpty() && queue.isEmpty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}