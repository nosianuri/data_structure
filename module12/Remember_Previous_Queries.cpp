#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insert(Node*& head, Node*& tail, int n, int v) {
    Node* newNode = new Node(v);
    if (n == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    } else if (n == 1) {
        newNode->prev = tail;
        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL) {
            head = newNode;
        }
    } else if (n == 2) {
        if (v < 0 || v >= INT_MAX) {
        } else {
            auto it = head;
            for (int i = 0; i < v && it != NULL; ++i) {
                it = it->next;
            }
            if (it != NULL) {
                if (it->prev != NULL) {
                    it->prev->next = it->next;
                } else {
                    head = it->next;
                }
                if (it->next != NULL) {
                    it->next->prev = it->prev;
                } else {
                    tail = it->prev;
                }
                delete it;
            }
        }
    }
}
void print_list(Node* head) {
    cout << "L -> ";
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_reverse_list(Node* tail) {
    cout << "R -> ";
    Node* tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
int main() {
    int q;
    cin >> q;
    Node* head = NULL;
    Node* tail = NULL;
    while (q--) {
        int n, v;
        cin >> n >> v;
        insert(head, tail, n, v);
        print_list(head);
        print_reverse_list(tail);
    }

    return 0;
}