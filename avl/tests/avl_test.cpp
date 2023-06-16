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

TEST(Rotations, SimpleLeft)
{
    AVLTree avl = AVLTree();

    avl.insert("1", 1);
    avl.insert("2", 2);
    avl.insert("3", 3);

    std::string s = avl.printPreOrder();

    EXPECT_EQ("2, 1, 3", s);
}

TEST(Rotations, SimpleLeftRight)
{
    AVLTree avl = AVLTree();

    avl.insert("3", 3);
    avl.insert("1", 1);
    avl.insert("2", 2);

    std::string s = avl.printPreOrder();

    EXPECT_EQ("2, 1, 3", s);
}

TEST(Rotations, SimpleRight)
{
    AVLTree avl = AVLTree();

    avl.insert("3", 3);
    avl.insert("2", 2);
    avl.insert("1", 1);

    std::string s = avl.printPreOrder();

    EXPECT_EQ("2, 1, 3", s);
}


TEST(Rotations, SimpleRightLeft)
{
    AVLTree avl = AVLTree();

    avl.insert("1", 1);
    avl.insert("3", 3);
    avl.insert("2", 2);

    std::string s = avl.printPreOrder();

    EXPECT_EQ("2, 1, 3", s);
}

TEST(Overall, AllRotAndPreOrder)
{
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

    EXPECT_EQ("N, I, H, A, L, K, M, P, O, Q", avl.printPreOrder());
}

TEST(Overall, AllRotAndPostOrder)
{
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

    EXPECT_EQ("A, H, K, M, L, I, O, Q, P, N", avl.printPostOrder());
}

TEST(Auxillary, getHeight1)
{
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

    EXPECT_EQ(4, avl.getHeight());  
}

TEST(Auxillary, getHeight2)
{
    AVLTree avl = AVLTree();
    avl.insert("1", 1);
    avl.insert("7", 7);
    avl.insert("3", 3);
    avl.insert("5", 5);
    avl.insert("9", 9);

    EXPECT_EQ("3, 1, 7, 5, 9", avl.printPreOrder());
    EXPECT_EQ(3, avl.getHeight());
}

TEST(Removal, Deg0_Leaf1)
{
    AVLTree avl = AVLTree();
    avl.insert("1", 1);
    avl.insert("2", 2);
    avl.insert("3", 3);
    avl.insert("4", 4);
    avl.insert("5", 5);
    avl.insert("6", 6);
    avl.insert("7", 7);

    avl.remove(7);

    EXPECT_EQ("4, 2, 1, 3, 6, 5", avl.printPreOrder());
}

TEST(Removal, Deg0_Leaf2)
{
    AVLTree avl = AVLTree();
    avl.insert("1", 1);
    avl.insert("2", 2);
    avl.insert("3", 3);
    avl.insert("4", 4);
    avl.insert("5", 5);
    avl.insert("6", 6);
    avl.insert("7", 7);

    avl.remove(3);

    EXPECT_EQ("4, 2, 1, 6, 5, 7", avl.printPreOrder());
}

TEST(Removal, Deg0_Root)
{
    AVLTree avl = AVLTree("1", 1);

    avl.remove(1);

    avl.insert("2", 2);

    EXPECT_EQ("2", avl.printPreOrder());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}