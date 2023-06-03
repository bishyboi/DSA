#include "include/iqr.h"

int main()
{
    int set[9] = {1,2,3,4,5,6,7,8,9};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    interQuartile(head);
}