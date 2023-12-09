#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int find_difference_value(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    vector<int> v;
    Node *tmp = head;
    while (tmp != NULL)
    {
        v.push_back(tmp->val);
        tmp = tmp->next;
    }
    if (v.size() > 0)
    {
        int minVal = *min_element(v.begin(), v.end());
        int maxVal = *max_element(v.begin(), v.end());
        return maxVal - minVal;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int val;
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int result = find_difference_value(head);
    cout << result << endl;
    Node *tmp = head;
    while (tmp != NULL)
    {
        Node *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    return 0;
}