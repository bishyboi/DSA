#include "../src/include/avl.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(Basic, Initialization)
{
    const std::string name = "Bishoy";
    const int id= 12345678;
    AVLTree avl = AVLTree(name, id);

    EXPECT_EQ(name, avl.root->getName());
    EXPECT_EQ(id, avl.root->getID());
}

TEST(Basic, SimpleInsertionLeft)
{
    const std::string name = "Bishoy";
    const int id= 12345678;
    AVLTree avl = AVLTree(name, id);

    const std::string insert_name = "Jeff";
    const int insert_id = 12345679;

    avl.insert(insert_name, insert_id);

    EXPECT_EQ(insert_name, avl.root->right->getName());
    EXPECT_EQ(insert_id, avl.root->right->getID());
}

TEST(Basic, SimpleInsertionRight)
{
    const std::string name = "Bishoy";
    const int id= 12345679;

    AVLTree avl = AVLTree(name, id);

    const std::string insert_name = "Jeff";
    const int insert_id = 12345678;
    
    avl.insert(insert_name, insert_id);

    EXPECT_EQ(insert_name, avl.root->left->getName());
    EXPECT_EQ(insert_id, avl.root->left->getID());
}

TEST(Basic, InsertionFalse)
{
    AVLTree avl = AVLTree();
    avl.insert("jeff", 2);
    avl.insert("jeef", 1);
    avl.insert("jef", 4);
    avl.insert("bob", 3);

    EXPECT_EQ(false, avl.insert("fatima", 3)); 
}

TEST(Basic, InOrderTraversalPrint)
{
    AVLTree avl = AVLTree("aubergine", 0);
    avl.insert("cat stevens", 2);
    avl.insert("barry allen", 1);
    avl.insert("the flash", 6);
    avl.insert("kal-el", 4);
    avl.insert("clark kent", 3);
    avl.insert("superman", 5);

    EXPECT_EQ("aubergine, barry allen, cat stevens, clark kent, kal-el, superman, the flash", avl.printInOrder());
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}