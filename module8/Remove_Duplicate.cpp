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
Node *insert_tail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return head;
    }
    Node *tmp = head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return head;
}

Node *remove_duplicates(Node *head)
{
    Node *prevNode = head;
    while (prevNode != NULL)
    {
        Node *removeNode = prevNode;
        while (removeNode->next != NULL)
        {
            if (removeNode->next->val == prevNode->val)
            {
                Node *duplicate = removeNode->next;
                removeNode->next = removeNode->next->next;
                delete duplicate;
            }
            else{
                removeNode = removeNode->next;
            }
        }
        prevNode = prevNode->next;
    }
    return head;
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
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        head = insert_tail(head, val);
    }
    head = remove_duplicates(head);
    print_list(head);
    return 0;
}