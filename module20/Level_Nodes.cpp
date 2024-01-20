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

vector<int> getNodeLevel(Node* root, int levelResult) {
    vector<int> nodes;
    if (root == NULL || levelResult < 0) {
        return nodes;
    }
    queue<pair<Node*, int>> q; 
    q.push({root, 0});
    while (!q.empty()) {
        Node* pos = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level == levelResult) {
            nodes.push_back(pos->val);
        }
        if (pos->left != NULL) {
            q.push({pos->left, level + 1});
        }
        if (pos->right != NULL) {
            q.push({pos->right, level + 1});
        }
    }
    return nodes;
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
    int levelResult;
    cin >> levelResult;
    vector<int> nodeLevel = getNodeLevel(root, levelResult);
    if (nodeLevel.empty()) {
        cout << "Invalid" << endl;
    } else {
        for (int val : nodeLevel) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}