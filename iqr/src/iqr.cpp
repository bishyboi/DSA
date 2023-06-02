#include "include/iqr.h"

int main()
{
    int set[7] = {1,2,3,4,5,6,7};
    Node* head = setToList(set, sizeof(set) / sizeof(int));
    interQuartile(head);
}