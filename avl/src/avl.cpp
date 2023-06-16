#include "include/avl.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    AVLTree avl = AVLTree();

    avl.insert("seen", 1);
    avl.insert("seven", 2);
    avl.insert("seven", 3);
    avl.insert("seven", 4);
    avl.insert("se7en", 5);
    avl.insert("seven", 6);
    avl.insert("sven", 7);

    avl.inOrderSearch("sixteen");
}

