#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

int totalNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSide = totalNodes(root->left);
    int rightSide = totalNodes(root->right);
    return max(leftSide, rightSide) + 1;
}

bool isCorrect(Node* root) {
    if (root == NULL) {
        return true;
    }
    int height = totalNodes(root);
    int expectNode = pow(2, height) - 1;
    int mainNode = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current != NULL) {
            mainNode++;
            q.push(current->left);
            q.push(current->right);
        }
    }
    return expectNode == mainNode;
}

int main() {
    int val;
    cin >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    if (isCorrect(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}