#pragma once
#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node *q1 = nullptr;
    Node *q3 = nullptr;

    return 0.0;   
}

Node* setToList(int arr[], int size)
{
    Node *head = new Node();
    head->value = arr[0];

    for(int i=1; i< size; i++)
    {
        insertEnd(head, arr[i]);
    }
    return head;
}

void printLinkedList(Node* head)
{
    Node *current = head;

    while(current != nullptr)
    {
        std::cout<< current->value << ", ";
        current = current->next;
    }
}