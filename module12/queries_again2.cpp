#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
bool insert_head(Node*& head, Node*& tail, int x, int value) {
    Node* newNode = new Node(value);
    if (x < 0) {
        return false; 
    }
    if (x == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    } else {
        return false; 
    }
    return true; 
}

bool insert_tail(Node*& head, Node*& tail, int index, int value) {
    Node* newNode = new Node(value);
    if (index < 0) {
        return false; 
    }
    if (index == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    } else {
        Node* pos = head;
        for (int i = 0; i < index - 1; ++i) {
            if (pos == NULL) {
                return false; 
            }
            pos = pos->next;
        }
        if (pos == NULL) {
            return false; 
        }
        newNode->next = pos->next;
        newNode->prev = pos;
        if (pos->next != NULL) {
            pos->next->prev = newNode;
        }
        pos->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
    return true; 
}
void print_left_list(Node* head) {
    cout << "L -> ";
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_right_list(Node* tail) {
    cout << "R -> ";
    Node* tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, v;
        cin >> x >> v;
        if (insert_head(head, tail, x, v) || insert_tail(head, tail, x, v)) {
            print_left_list(head);
            print_right_list(tail);
        } else {
            cout << "Invalid" << endl;
        }
    }
    while (head != NULL) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}