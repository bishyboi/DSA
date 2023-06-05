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

    // if(head == nullptr || head->next == nullptr)
    // {
    //     return iqr;
    // } else if(head->next->next == nullptr){
    //     iqr = head->next->value - head->value;
    //     return iqr;
    // }

    Node *q1 = head;
    Node *q3 = head;
    Node *tail= head;

    int size=1; //Because all are pointing to the first element, we are assuming that size is already 1
    while(tail->next != nullptr)
    {
        if(size%4 != 3) // In a cycle of 4 moves, Q3 skips only the last move
            q3 = q3->next;
        
        // Why size mod 4 == 2? It's some modulus mafematics, draw a picture to see
        if(size%4 ==2 && size>4) // In a cycle of 4 moves, Q1 moves only on first move, skips all others
            q1 = q1->next;
        
        size++; // On size = 1, size is determined after checking if there is a first element
        tail = tail->next;
    }

    switch (size%4)
    {
        case 0:
            iqr = (((float)q3->value + (float)q3->next->value)/2.0) - (((float)q1->value + (float)q1->next->value)/2.0);
            break;
        
        case 1:
            iqr = (((float)q3->value + (float)q3->next->value)/2.0) - (((float)q1->value + (float)q1->next->value)/2.0);
            break;

        case 2:
            iqr = (q3->value) - (q1->next->value);
            break;

        case 3:
            iqr = q3->value - q1->value;
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