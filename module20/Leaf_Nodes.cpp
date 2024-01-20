#include<bits/stdc++.h>
using namespace std;
class Node
{
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

vector<int> leafVal;
void traverseAndCollectLeaf(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) {
        leafVal.push_back(root->val);
    }
    traverseAndCollectLeaf(root->left);
    traverseAndCollectLeaf(root->right);
}

Node* buildTree(vector<int>& levelOrder) {
    if (levelOrder.empty()) return NULL;
    int n = levelOrder.size();
    Node* root = new Node(levelOrder[0]);
    queue<Node*> nodeQueue;
    nodeQueue.push(root);
    int i = 1;
    while (i < n) {
        Node* current = nodeQueue.front();
        nodeQueue.pop();
        if (levelOrder[i] != -1) {
            current->left = new Node(levelOrder[i]);
            nodeQueue.push(current->left);
        }
        i++;
        if (i < n && levelOrder[i] != -1) {
            current->right = new Node(levelOrder[i]);
            nodeQueue.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<int> values;
    int val;
    while (cin >> val) {
        values.push_back(val);
    }
    Node* root = buildTree(values);
    traverseAndCollectLeaf(root);
    sort(leafVal.rbegin(), leafVal.rend());
    cout << "";
    for (int v : leafVal) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}