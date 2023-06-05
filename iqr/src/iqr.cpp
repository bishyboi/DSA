#include "include/iqr.h"

int main()
{
    int set[5] = {1,2,3,4,5};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    interQuartile(head);
}