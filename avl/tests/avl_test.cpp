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

TEST(MultipleRots, AllRotAndPreOrder)
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

TEST(MultipleRots, AllRotAndPostOrder)
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

TEST(Height, getHeight1)
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

TEST(Height, getHeight2)
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

TEST(Removal_Deg0, Leaf1)
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

TEST(Removal_Deg0, Leaf2)
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

TEST(Removal_Deg0, Root)
{
    AVLTree avl = AVLTree();

    avl.insert("barry allen", 35);
    avl.remove(35);

    EXPECT_EQ("", avl.printPreOrder());

    avl.insert("2", 2);

    EXPECT_EQ("2", avl.printPreOrder());
}

TEST(Removal_Deg1, RightChild_NoChild)
{
    AVLTree avl = AVLTree("4", 4);

    avl.insert("2", 2);
    avl.insert("6", 6);
    avl.insert("5", 5);

    avl.remove(6);

    EXPECT_EQ("4, 2, 5", avl.printPreOrder());
}

TEST(Removal_Deg1, ROOT_RightChild_NoChild)
{
    AVLTree avl = AVLTree("4", 4);
    avl.insert("6", 6);

    avl.remove(4);

    EXPECT_EQ("6", avl.printPreOrder());
}

TEST(Removal_Deg1, LeftChild_NoChild)
{
    AVLTree avl = AVLTree("4", 4);

    avl.insert("2", 2);
    avl.insert("5", 5);
    avl.insert("1", 1);

    avl.remove(1);

    EXPECT_EQ("4, 2, 5", avl.printPreOrder());
}

TEST(Removal_Deg1, ROOT_LeftChild_NoChild)
{
    AVLTree avl = AVLTree("4", 4);

    avl.insert("3", 3);
    
    avl.remove(4);

    EXPECT_EQ("3", avl.printPreOrder());
}

TEST(Removal_Deg2, DirectChild_NoChild)
{
    AVLTree avl = AVLTree("4", 4);

    avl.insert("2", 2);
    avl.insert("7", 7);
    avl.insert("8", 8);
    avl.insert("6", 6);

    avl.remove(7);

    EXPECT_EQ("4, 2, 8, 6", avl.printPreOrder());
}

TEST(Removal_Deg2, ROOT_DirectChild_NoChild)
{
    AVLTree avl = AVLTree("4", 4);

    avl.insert("2", 2);
    avl.insert("5", 5);

    avl.remove(4);

    EXPECT_EQ("5, 2", avl.printPreOrder());
}

TEST(Removal_Deg2, DirectChild_Child)
{
    AVLTree avl = AVLTree("5", 5);
    
    avl.insert("4", 4);
    avl.insert("8", 8);
    avl.insert("3", 3);
    avl.insert("6", 6);
    avl.insert("10", 10);
    avl.insert("12", 12);

    avl.remove(8);

    EXPECT_EQ("5, 4, 3, 10, 6, 12", avl.printPreOrder());
}

TEST(Removal_Deg2, ROOT_DirectChild_Child)
{
    AVLTree avl = AVLTree("5", 5);
    
    avl.insert("3", 3);
    avl.insert("9", 9);
    avl.insert("10", 10);

    avl.remove(5);

    EXPECT_EQ("9, 3, 10", avl.printPreOrder());
}

TEST(Removal_Deg2, IndirectChild_NoChild)
{
    AVLTree avl = AVLTree("10", 10);

    avl.insert("5", 5);
    avl.insert("15", 15);
    avl.insert("0", 0);
    avl.insert("7", 7);
    avl.insert("12", 12);
    avl.insert("17", 17);
    avl.insert("-1", -1);
    avl.insert("6", 6);
    avl.insert("8", 8);

    avl.remove(5);

    EXPECT_EQ("10, 6, 0, -1, 7, 8, 15, 12, 17", avl.printPreOrder());
}

TEST(Removal_Deg2, ROOT_IndirectChild_NoChild)
{
    AVLTree avl = AVLTree("5", 5);
    
    avl.insert("3", 3);
    avl.insert("10", 10);
    avl.insert("2", 2);
    avl.insert("4", 4);
    avl.insert("6", 6);
    avl.insert("12", 12);

    avl.remove(5);

    EXPECT_EQ("6, 3, 2, 4, 10, 12", avl.printPreOrder());
}

TEST(Removal_Deg2, IndirectChild_Child)
{
    AVLTree avl = AVLTree("50", 50);
    
    avl.insert("25", 25);
    avl.insert("75", 75);

    avl.insert("12", 12);
    avl.insert("37", 37);
    avl.insert("63", 63);
    avl.insert("87", 87);

    avl.insert("6", 6);
    avl.insert("20", 20);
    avl.insert("30", 30);
    avl.insert("45", 45);
    avl.insert("55", 55);
    avl.insert("70", 70);
    avl.insert("80", 80);
    avl.insert("100", 100);

    avl.insert("3", 3);
    avl.insert("10", 10);
    avl.insert("15", 15);
    avl.insert("23", 23);
    avl.insert("26", 26);
    avl.insert("33", 33);
    avl.insert("40", 40);
    avl.insert("47", 47);
    avl.insert("53", 53);
    avl.insert("60", 60);
    avl.insert("66", 66);
    avl.insert("72", 72);
    avl.insert("77", 77);
    avl.insert("83", 83);
    avl.insert("90", 90);
    avl.insert("130", 130);
    
    avl.insert("76", 76);
    avl.insert("78", 78);

    avl.remove(75);

    EXPECT_EQ("50, 25, 12, 6, 3, 10, 20, 15, 23, 37, 30, 26, 33, 45, 40, 47, 76, 63, 55, 53, 60, 70, 66, 72, 87, 80, 77, 78, 83, 100, 90, 130", avl.printPreOrder());
}

TEST(Removal_Deg2, ROOT_IndirectChild_Child)
{
    AVLTree avl = AVLTree("50", 50);
    
    avl.insert("25", 25);
    avl.insert("75", 75);

    avl.insert("12", 12);
    avl.insert("37", 37);
    avl.insert("63", 63);
    avl.insert("87", 87);

    avl.insert("6", 6);
    avl.insert("20", 20);
    avl.insert("30", 30);
    avl.insert("45", 45);
    avl.insert("55", 55);
    avl.insert("70", 70);
    avl.insert("80", 80);
    avl.insert("100", 100);

    avl.insert("3", 3);
    avl.insert("10", 10);
    avl.insert("15", 15);
    avl.insert("23", 23);
    avl.insert("26", 26);
    avl.insert("33", 33);
    avl.insert("40", 40);
    avl.insert("47", 47);
    avl.insert("53", 53);
    avl.insert("60", 60);
    avl.insert("66", 66);
    avl.insert("72", 72);
    avl.insert("77", 77);
    avl.insert("83", 83);
    avl.insert("90", 90);
    avl.insert("130", 130);

    avl.remove(50);

    EXPECT_EQ("53, 25, 12, 6, 3, 10, 20, 15, 23, 37, 30, 26, 33, 45, 40, 47, 75, 63, 55, 60, 70, 66, 72, 87, 80, 77, 83, 100, 90, 130", avl.printPreOrder());
}

TEST(Removal_Deg2, BrianBriana)
{
    AVLTree avl = AVLTree("4", 4);
    avl.insert("3", 3);
    avl.insert("8", 8);
    avl.insert("9", 9);

    avl.remove(4);
    avl.removeInOrder(2);

    EXPECT_EQ("3, 8", avl.printInOrder());
}

TEST(Removal_N, idkMan)
{
    AVLTree avl = AVLTree();
    
    avl.insert("10", 10);

    avl.insert("5", 5);
    avl.insert("15", 15);
    
    avl.insert("0", 0);
    avl.insert("7", 7);
    avl.insert("12", 12);
    avl.insert("17", 17);

    avl.removeInOrder(3);

    EXPECT_EQ("10, 5, 7, 15, 12, 17", avl.printPreOrder());
}

TEST(Search, InOrderSearch_Successful)
{
    AVLTree avl = AVLTree();

    avl.insert("seen", 1);
    avl.insert("seven", 2);
    avl.insert("seven", 3);
    avl.insert("seven", 4);
    avl.insert("se7en", 5);
    avl.insert("seven", 6);
    avl.insert("sven", 7);

    EXPECT_EQ("2\n3\n4\n6", avl.inOrderSearch("seven"));
}


TEST(Search, InOrderSearch_UnSuccessful)
{
    AVLTree avl = AVLTree();

    avl.insert("seen", 1);
    avl.insert("seven", 2);
    avl.insert("seven", 3);
    avl.insert("seven", 4);
    avl.insert("se7en", 5);
    avl.insert("seven", 6);
    avl.insert("sven", 7);

    EXPECT_EQ("unsuccessful", avl.inOrderSearch("sixteen"));
}

TEST(Search, BasicSearch_Successful)
{
    AVLTree avl = AVLTree();

    avl.insert("3", 3);
    avl.insert("taquavion", 6969);
    avl.insert("barry allen", 32);
    avl.insert("superman", 555);
    avl.insert("batman", 31);
    avl.insert("bruce wayne", 68);

    EXPECT_EQ("batman", avl.search(31));
}

TEST(Search, BasicSearch_UnSuccessful)
{
    AVLTree avl = AVLTree();

    avl.insert("3", 3);
    avl.insert("taquavion", 6969);
    avl.insert("barry allen", 32);
    avl.insert("superman", 555);
    avl.insert("batman", 31);
    avl.insert("bruce wayne", 68);

    EXPECT_EQ("unsuccessful", avl.search(69));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}