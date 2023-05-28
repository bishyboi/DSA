#include "include/books.h"

set<string> getRepo(vector<vector<string>> arr)
{
    set<string> book_repo;

    for(auto row: arr) // O(row) operations, where row is the number of rows in the array
    {
        for(auto col: row) // O(col) operations, where col is the number of columns in the array
        {
            book_repo.insert(col); // O(log(n)) operation
            // How does the time complexity change with respect to string length?
        }
    }

    return book_repo;
}

void printSet(set<string> set)
{
    for(auto it = set.begin(); it != set.end(); it++)
    {
        std::cout<< *it << endl;
    }
}

int main(){
    vector <vector<string>> library
    {
        {"don quixote", "1984", "freakonomics"},
        {"burnt sugar", "burnt sugar", "midnight's children"},
        {"molecular biology", "don quixote", "burnt sugar"}
    };

    printSet(getRepo(library));
    }