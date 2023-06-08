#include "../src/include/avl.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(Basic, Initialization)
{
    AVLTree avl = AVLTree::AVLTree("Bishoy", 12345678);

    std::cout << avl.root->name << ", " << avl.root->gator_id ; 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}