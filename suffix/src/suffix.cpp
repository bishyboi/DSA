#include "include/suffix.h"
#include <iostream>

int suffixCount(std::string S, int L)
{
    if(L>S.size())
        return 0;

    int matches=0;

    std::string suffix = S.substr(S.size()-L, S.npos);

    int i =0;
    std::string istring;
    while(i<S.length() || (i+L) < S.length())
    {
        if (S[i] == suffix[0])
        {
            istring = S.substr(i,L);
            //std::cout<< "istring: " << istring << " | suffix: " << suffix << std::endl;

            if(istring == suffix){
                matches++;
                i+=L;
            } else{
                i++;
            }
        } else{
            i++;
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