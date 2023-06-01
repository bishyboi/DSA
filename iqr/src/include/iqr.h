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
    Node *q1 = head;
    Node *q3 = head;
    Node *tail= head;

    int count=0;
    while(tail != nullptr)
    {

        // TODO: add logic for when q1 and q2 needs to account for q1 and q3 lying on evens (must average two numbers)
        //logic for determining when to move q1 and q3
        if(count%4 >= 1)
            q3 = q3->next;
        
        if(count%4 ==3)
            q1 = q1->next;
        
        tail = tail->next;
        count++;
    }

    return ((float)(q1->value +q3->value))/2.0;   
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