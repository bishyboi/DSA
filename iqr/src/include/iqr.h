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
    float iqr =0.0;
    Node *q1 = head;
    Node *q3 = head;
    Node *tail= head;

    int size=0;
    while(tail->next != nullptr)
    {
        size++; // On size = 1, size is determined after checking if there is a first element
        tail = tail->next;

        if(size%4  >0) // In a cycle of 4 moves, Q3 skips the first move and does all others
            q3 = q3->next;
        
        if(size%4 ==3) // In a cycle of 4 moves, Q1 skips the first 3 moves and only moves on the last
            q1 = q1->next;
    }

    switch (size%4)
    {
    case 0:
        iqr = ((q3->value + q3->next->value)/2.0) - ((q1->value + q1->next->value)/2.0);
        break;
    
    case 1:
        iqr = ((q3->next->next->value + q3->next->value)/2.0) - ((q1->value + q1->next->value)/2.0);
        break;
    }

    return iqr;
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