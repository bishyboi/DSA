#include "include/suffix.h"
#include <iostream>


int suffixCount(std::string S, int L)
{
    int matches=0;

    std::string suffix = S.substr(S.length()-L, L);

    int i =0;
    std::string istring;
    while(i<S.length() || (i+L)< S.length())
    {
        if (S[i] == suffix[0])
        {
            istring = S.substr(S[i],L);
            if(istring == suffix){
                matches++;
                i+=L;
            } else{
                i++;
            }   
        }
    }
    return matches;
}