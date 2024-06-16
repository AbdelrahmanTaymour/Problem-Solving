#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

void InsertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->value = value;

    newNode->next = head;
    head = newNode;
}

Node *Find(Node *head, int Value)
{
    while (head != NULL)
    {
        if (head->value == Value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void InsertAfter(Node *prevNode, int newValue)
{
    if (prevNode == NULL)
    {
        cout << "\nPrevNode Cannot be NULL.\n";
        return;
    }

    Node *newNode = new Node();
    newNode->value = newValue;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

void InsertAtEnd(Node *&head, int NewValue)
{
    Node *newNode = new Node();
    newNode->value = NewValue;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *P = head;
    while (P->next != NULL)
    {
        P = P->next;
    }

    P->next = newNode;
    newNode->next = NULL;
}

void DeleteNode(Node *&Head, int item)
{
    Node *delptr = Head;

    if (Head == NULL)
    {
        return;
    }

    if (Head->value == item)
    {
        Head = Head->next;
        delete delptr;
        return;
    }

    Node *pre = NULL;

    while (delptr->value != item)
    {
        pre = delptr;
        delptr = delptr->next;
    }

    pre->next = delptr->next;
    delete delptr;
}

void DeleteNode2(Node*&head, int item)
{
    if(head == NULL)
    return;

    Node* delptr = head;
    if(head->value == item)
    {
        head = head->next;
        delete delptr;
    }
    else
    {
        Node*Current = head;
        while(Current->next->value != item)
        {
            Current = Current->next;
        }
        delptr  = Current->next;
        Current = Current->next->next;
        delete delptr;
    }
}

void DeleteFirstNode(Node*&head)
{
    if(head == NULL)
        return;
    
    Node*DelPtr = head;
    head = head->next;
    delete DelPtr;
}

void DeleteLastNode(Node*& head)
{
    Node* Current = head, * Prev = head;

    if (head == NULL)
    {
        return;
    }

    if (Current->next == NULL) {
        head = NULL;
        delete Current;//free from memory
        return;
    }

    // Find the key to be deleted
    while (Current != NULL && Current->next != NULL) {
        Prev = Current;
        Current = Current->next;
    }

    // Remove the node
    Prev->next = NULL;
    delete Current;//free from memory
}

void DeleteLastNode2(Node*&head)
{
    if(head == NULL)
        return;
    
    Node* DelPtr = head;
    
    if(head->next == NULL)
    {
        head = NULL;
        delete DelPtr;
        return;
    }
    else
    {
        Node* Current = head;
        while(Current->next->next!=NULL)
        {
            Current = Current->next;
        }
        DelPtr = Current->next;
        Current->next = NULL;
        delete DelPtr;
    }
}
