#include "books.h"

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