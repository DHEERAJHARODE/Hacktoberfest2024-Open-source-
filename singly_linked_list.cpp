#include <bits/stdc++.h>
using namespace std;
#include "listclass.cpp"

void print(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << count;
}

void append(node **head)
{
    int data;
    cin >> data;

    node *newnode = new node(data);

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}
node *insert(node *head)
{

    int pos, data;
    cin >> pos >> data;

    node *newnode = new node(data);
    node *temp = head;

    if (pos == 1)
    {
        newnode->next = temp;
        head = newnode;
        return head;
    }

    int i = 0;
    while (i < pos - 2)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

node *insertNodeRe(node *head, int data, int pos)
{

    if (pos == 1)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }
    node *temp = insertNodeRe(head->next, data, pos - 1);
    head->next = temp;
    return head;
}

node *deleteNodeRe(node *head, int pos)
{
    if (head->next == NULL)
    {
        return head;
    }
    if (pos == 1)
    {
        head = head->next;
        return head;
    }
    node *temp = deleteNodeRe(head->next, pos - 1);
    head->next = temp;
    return head;
}

node *deleteNode(node *head)
{

    int pos;
    cin >> pos;

    node *temp = head;

    if (pos == 1)
    {

        head = temp->next;
        return head;
    }

    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    temp->next = (temp->next)->next;

    return head;
}

node *multiInput()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            cin >> data;
        }

        else
        {

            tail->next = newnode;
            tail = tail->next;

            cin >> data;
        }
    }

    return head;
}

int main()
{

    node a(1);
    node *head = &a;
    node b(2);
    node c(3);
    node d(4);
    node e(5);
    node f(6);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    print(head);
    // head = insert(head);
    int data, pos;
    cin >> pos >> data;
    head = insertNodeRe(head, data, pos);
    print(head);
    // head = deleteNode(head);
    cin >> pos;
    head = deleteNodeRe(head, pos);
    print(head);

    return 0;
}
