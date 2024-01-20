#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printLeft(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        printLeft(root->left);
    }
    cout << root->val << " ";
}

void printRight(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    if (root->right != NULL) {
        printRight(root->right);
    }
}

void printOuterSide(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL ) {
        cout << root->val << " ";
    }
    printLeft(root->left);
    if (root->left != NULL || root->right != NULL) {
        cout << root->val << " ";
    }
    printRight(root->right);
}

int main() {
    int val;
    cin >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* pos = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            pos->left = new Node(leftVal);
            q.push(pos->left);
        }
        cin >> rightVal;
        if (rightVal != -1) {
            pos->right = new Node(rightVal);
            q.push(pos->right);
        }
    }
    printOuterSide(root);
    return 0;
}