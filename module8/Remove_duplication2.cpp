#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert_tail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void remove_duplicate(Node* &head) {
    Node* prevNode = head;
    while (prevNode != NULL) {
        Node* rmvNode = prevNode;
        while (rmvNode->next != NULL) {
            if (rmvNode->next->data == prevNode->data) {
                Node* duplicate = rmvNode->next;
                rmvNode->next = rmvNode->next->next;
                delete duplicate;
            } else {
                rmvNode = rmvNode->next;
            }
        }
        prevNode = prevNode->next;
    }
}

void print_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    int val;
    Node* head = NULL;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_tail(head, val);
    }
    remove_duplicate(head);
    print_list(head);
    return 0;
}