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

int nonLeafNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return root->val + nonLeafNodes(root->left) + nonLeafNodes(root->right);
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
    int result = nonLeafNodes(root);
    cout << result << endl;
    return 0;
}