#pragma once
#include <iostream>

int get_parent(int current_index)
{
    return (current_index - 1) / 2;
}

int get_left(int current_index)
{
    return 2 * current_index + 1;
}

int get_right(int current_index)
{
    return 2 * current_index + 2;
}

void swap_val(int arr[], int current_index, int new_index)
{
    int temp = arr[current_index];
    arr[current_index] = arr[new_index];
    arr[new_index] = temp;
}

void heapify(int arr[], int size, int current)
{
    if (arr[current] > arr[get_left(current)] && arr[current] > arr[get_right(current)])
        return;
    else if (arr[current] < arr[get_left(current)] && arr[current] < arr[get_right(current)])
    {
        if(arr[get_left(current)] > arr[get_right(current)])
        {
            swap_val(arr, current, get_left(current));
            current = get_left(current);
        }
        else
        {
            swap_val(arr,current, get_right(current));
            current = get_right(current);
        }

        heapify(arr, size, current);
    }
    else if (arr[current] < arr[get_left(current)])
    {
        swap_val(arr, current, get_left(current));
        current = get_left(current);
    }
    else if (arr[current] < arr[get_right(current)])
    {
        swap_val(arr,current, get_right(current));
        current = get_right(current);
    }
    else{
        std::cout<< "what the fuck";
    }
}

int *extractMax(int arr[], int size)
{
    int current = 0;
    swap_val(arr, 0, size - 1);
    arr[size - 1] = 0;

    heapify(arr, size, 0);

    return arr;
}