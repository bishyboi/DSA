#include "include/suffix_count.h"
#include <iostream>

int suffixCount(std::string S, int L)
{
    int matches=0;

    std::string suffix = S.substr(S.size()-L, S.npos);

    std::string istring;
    
    for(int i=0; i<S.size()-L+1; i++)
    {
        istring = S.substr(i,L);
        //std::cout<< "istring: " << istring << " | suffix: " << suffix << std::endl;

        if(istring == suffix){
            matches++;
        } 

    }
    return matches;
}

// int main()
// {
//     std::string S = "et tu, brute";
//     int L = 1;

//     std::cout<< "Expected: 2" << std::endl<< "Received: "<< suffixCount(S,L);
// }