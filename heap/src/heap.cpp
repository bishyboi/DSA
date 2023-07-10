#include "include/heap.h"

int main()
{
    int arr[] = {11, 5, 8, 3, 4};
    int arr_eq[] = {8, 5, 4, 3};
    
    std::string arr_s = arrstr(arr, std::size(arr));
    std::string eq_s = arrstr(arr_eq, std::size(arr_eq));
    std::string in_s = arrstr(extractMax(arr, std::size(arr)), std::size(arr));

    std::cout<< "Input: " << arr_s << std::endl;
    std::cout<< "Output: " << in_s << std::endl;
    std::cout<< "Expected Output: "<<  eq_s << std::endl;
}