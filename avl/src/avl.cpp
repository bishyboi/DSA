#include "include/avl.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    AVLTree avl = AVLTree();
    avl.insert("M", 6);
    avl.insert("N", 7);
    avl.insert("O", 8);
    avl.insert("L", 5);
    avl.insert("K", 4);
    avl.insert("Q", 10);
    avl.insert("P", 9);
    avl.insert("H", 2);
    avl.insert("I", 3);
    avl.insert("A", 1);

    bool test = ("N, I, H, A, L, K, M, P, O, Q" == avl.printPreOrder());
}

