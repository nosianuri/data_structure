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
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    Node *tmp = head;
    while (tmp != NULL)
    {
        minVal = min(minVal, tmp->val);
        maxVal = max(maxVal, tmp->val);
        tmp = tmp->next;
    }
    return maxVal - minVal;
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