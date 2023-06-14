#include "include/avl.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    AVLTree avl = AVLTree();

    avl.insert("1", 1);
    avl.insert("2", 2);
    avl.insert("3", 3);

    std::string s = avl.printPreOrder();
}

