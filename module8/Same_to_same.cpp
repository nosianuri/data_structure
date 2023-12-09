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

void check_link_list(Node *&head, Node *&tail)
{
    int val;
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
}

void equal_link_list(Node *head1, Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val != head2->val)
        {
            cout << "NO" << endl;
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == head2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    check_link_list(head1, tail1);

    Node *head2 = NULL;
    Node *tail2 = NULL;
    check_link_list(head2, tail2);
    equal_link_list(head1, head2);
    Node *tmp1 = head1;
    while (tmp1 != NULL)
    {
        Node *next = tmp1->next;
        delete tmp1;
        tmp1 = next;
    }
    Node *tmp2 = head2;
    while (tmp2 != NULL)
    {
        Node *next = tmp2->next;
        delete tmp2;
        tmp2 = next;
    }
    return 0;
}