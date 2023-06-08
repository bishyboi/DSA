#pragma once
#include <iostream>
#include <string>
//findHeight() should be recursive, returning the height of the next node +1
//findBalanceFactor() should be recursive, returning the sums of left and right heights

//left-right on  0, -1, 2

struct AVLTree{
    struct Node{
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent;

        std::unique_ptr<std::string> name;
        std::unique_ptr<int> gator_id;

        Node(const std::string name, const int id, std::shared_ptr<Node> p=nullptr, std::shared_ptr<Node> l=nullptr , std::shared_ptr<Node> r=nullptr)
        {

            this->left = l;
            this->right = r;
            this->parent = p;
            this->name = std::make_unique<std::string>(name);
            this->gator_id = std::make_unique<int>(id);
        }

        ~Node()
        {
            this->left.reset();
            this->right.reset();
            this->parent.reset();

            this->name.reset();
            this->gator_id.reset();
        }
    };
    
    std::unique_ptr<Node> root;

    /**
     * @brief 
     * Add a Student object into the tree with the specified name, NAME and GatorID number, ID.
     * Balance the tree automatically if necessary.
     * The ID must be unique.
     * The ID and NAME must satisfy the constraints stated below.
     * Also, prints “successful” if insertion is successful and prints “unsuccessful” otherwise.
     * NAME identifier will be separated by double inverted commas for parsing, e.g. "Josh Smith".
     * 
     * @param name Name of the Student
     * @param id Unique 8-Digit Integer ID number
     */
    void insert(const std::string name, const int id)
    {
        //TODO: implement lol
    }

    /**
     * @brief 
     * Find and remove the account with the specified ID from the tree.
     * [Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit]
     * If deletion is successful, print “successful”.
     * If the ID does not exist within the tree, print “unsuccessful”.
     * You must prioritize replacing a removed node with its inorder successor for the case where the deleted node has two children.
     * 
     * @param id Unique 8-Digit ID number
     */
    void remove(const int id)
    {
        //TODO: implement
    }

    /**
     * @brief 
     * Search for the student with the specified ID from the tree.
     * If the ID was found, print out their NAME.
     * If the ID does not exist within the tree, print “unsuccessful”.
     * 
     * @param id Unique 8-Digit ID number
     */
    void search(const int id)
    {
        //TODO: implement
    }

    /**
     * @brief 
     * Search for the student with the specified name, NAME in the tree.
     * If the student name was found, print the associated ID.
     * If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
     * If the name does not exist within the tree, print “unsuccessful”.
     * NAME identifier will be surrounded by double quotes for parsing, e.g. "Josh Smith".
     * 
     * @param name Name of the student(s)
     */
    void search(const std::string name)
    {
        //TODO: implement
    }

    /**
     * @brief 
     * Print out a comma separated in-order traversal of the names in the tree. LNR
     */
    void printInOrder()
    {}

    /**
     * @brief 
     * Print out a comma separated pre-order traversal of the names in the tree. NLR
     */
    void printPreOrder()
    {}

    /**
     * @brief 
     * Print out a comma separated post-order traversal of the names in the tree. LRN
     */
    void printPostOrder()
    {}

    /**
     * @brief 
     * Prints the number of levels that exist in the tree.
     * Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has 4 levels.
     * AKA: Find max height of tree
     */
    void printLevelCount()
    {}

    /**
     * @brief 
     * Remove the Nth GatorID from the inorder traversal of the tree (N = 0 for the first item, etc).
     * If removal is successful, print “successful”.
     * [Optional: Balance the tree automatically if necessary. We will test your code only on cases where the tree will be balanced before and after the deletion. So you can implement a BST deletion and still get full credit]
     * If the Nth GatorID does not exist within the tree, print “unsuccessful”.
     * @param n Nth Gator-ID from the IN-ORDER traversal
     */
    void removeInOrder(const int n)
    {}
};