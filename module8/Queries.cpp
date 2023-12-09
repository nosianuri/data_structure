#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
void insert_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void delete_index(Node *&head, int pos)
{
    if (!head)
        return;
    if (pos == 0)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node *tmp = head;
    for (int i = 0; tmp != NULL && i < pos - 1; i++)
    {
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp->next == NULL)
        return;
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            insert_head(head, v);
        }
        else if (x == 1)
        {
            insert_tail(head, v);
        }
        else if (x == 2)
        {
            delete_index(head, v);
        }
        print_list(head);
    }
    return 0;
}