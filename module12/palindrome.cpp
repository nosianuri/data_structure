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

bool check_palindrome(Node* head) {
    if (head == NULL) {
        return true;
    }
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next; 
    }
    while (head != tail && head->next != tail) {
        if (head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->prev; 
    }
    return (head->val == tail->val);
}
void print_palindrome(Node* head) {
    if (check_palindrome(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    print_palindrome(head);
    while (head != NULL) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}