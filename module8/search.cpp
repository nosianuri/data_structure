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

void index_linked_list(Node *head, int X)
{
    int index = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val == X)
        {
            cout << index << endl;
            return;
        }
        tmp = tmp->next;
        index++;
    }
    cout << -1 << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
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
        int X;
        cin >> X;
        index_linked_list(head, X);
        Node *tmp = head;
        while (tmp != NULL)
        {
            Node *next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }
    return 0;
}