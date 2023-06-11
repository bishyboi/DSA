#include "../src/include/levelsum.h"
#include <gtest/gtest.h>

TEST(Basic, EDGE_NULLPTR)
{
    TreeNode *root = nullptr;

    EXPECT_EQ(sumOfLevel(root,1), 0);
}

TEST(Basic, L0)
{
    TreeNode root = TreeNode(7);

    insert(&root, 2);
    insert(&root, 8);

    insert(&root, 0);
    insert(&root, 5);
    insert(&root, 12);
    
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 13);

    insert(&root, 3);
    insert(&root, 0);
    insert(&root, 9);
    insert(&root, 11);


    EXPECT_EQ(sumOfLevel(&root,0), 7);
}

TEST(Basic, L1)
{
    TreeNode root = TreeNode(7);

    insert(&root, 2);
    insert(&root, 8);

    insert(&root, 0);
    insert(&root, 5);
    insert(&root, 12);
    
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 13);

    insert(&root, 3);
    insert(&root, 0);
    insert(&root, 9);
    insert(&root, 11);


    EXPECT_EQ(sumOfLevel(&root,1), 10);
}

TEST(Basic, L2)
{
    TreeNode root = TreeNode(7);

    insert(&root, 2);
    insert(&root, 8);

    insert(&root, 0);
    insert(&root, 5);
    insert(&root, 12);
    
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 13);

    insert(&root, 3);
    insert(&root, 0);
    insert(&root, 9);
    insert(&root, 11);

    
    EXPECT_EQ(sumOfLevel(&root,2), 17);
}

TEST(Basic, L3)
{
    TreeNode root = TreeNode(7);

    insert(&root, 2);
    insert(&root, 8);

    insert(&root, 0);
    insert(&root, 5);
    insert(&root, 12);
    
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 13);

    insert(&root, 3);
    insert(&root, 0);
    insert(&root, 9);
    insert(&root, 11);

    
    EXPECT_EQ(sumOfLevel(&root,3), 33);
}

TEST(Basic, L4)
{
    TreeNode root = TreeNode(7);

    insert(&root, 2);
    insert(&root, 8);

    insert(&root, 0);
    insert(&root, 5);
    insert(&root, 12);
    
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 13);

    insert(&root, 3);
    insert(&root, 9);
    insert(&root, 11);

    
    EXPECT_EQ(sumOfLevel(&root,4), 23);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}