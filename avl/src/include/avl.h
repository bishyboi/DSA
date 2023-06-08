#pragma once
#include <iostream>
#include <string>
#include <memory>
// findHeight() should be recursive, returning the height of the next node +1
// findBalanceFactor() should be recursive, returning the sums of left and right heights

// left-right on  0, -1, 2

struct AVLTree
{
    struct Node
    {
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent;

        std::unique_ptr<std::string> name;
        std::unique_ptr<int> gator_id;

        Node(const std::string name, const int id, std::shared_ptr<Node> p = nullptr,
             std::shared_ptr<Node> l = nullptr, std::shared_ptr<Node> r = nullptr)
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

        std::string getName()
        {
            return *(this->name);
        }

        int getID()
        {
            return *(this->gator_id);
        }
    };

    std::shared_ptr<Node> root = nullptr;

    /**
     * @brief Construct a new AVLTree object
     */
    AVLTree()
    {}

    /**
     * @brief Construct a new AVLTree object
     *
     * @param name Initial Student Name for the root node
     * @param id Initial 8-Digit ID for the root node
     */
    AVLTree(const std::string name, const int id)
    {
        this->root = std::make_unique<Node>(name, id);
    }

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
    bool insert(const std::string name, const int id)
    {
        std::shared_ptr<Node> insertion = std::make_shared<Node>(name, id);

        if(this->root == nullptr)
        {
            this->root = insertion;
            return true;            
        }

        std::shared_ptr current = this->root;

        return insertOnNode(current, insertion);
    }

    // Detect if greater than or less than,
    // then check if theres a node already there.
    //  If theres a node already there,
    // repeat the check until there isn't a node where its about to be inserted
    bool insertOnNode(std::shared_ptr<Node> current, std::shared_ptr<Node> insertion)
    {
        if (insertion->getID() == current->getID())
        {
            return false;
        }
        else if (insertion->getID() > current->getID())
        {
            if (current->right != nullptr)
            {
                return insertOnNode(current->right, insertion);
            }
            else
            {
                current->right = std::move(insertion);
                return true;
            }
        }
        else
        {
            if (current->left != nullptr)
            {
                return insertOnNode(current->left, insertion);
            }
            else
            {
                current->left = std::move(insertion);
                return true;
            }
        }
    }

    /**
     * @brief
     * Find and remove the account with the specified ID from the tree.
     * [Optional: Balance the tree automatically if necessary.
     * We will test your code only on cases where the tree will be balanced before and after the deletion.
     * So you can implement a BST deletion and still get full credit]
     * If deletion is successful, print “successful”.
     * If the ID does not exist within the tree, print “unsuccessful”.
     * You must prioritize replacing a removed node with its in-order successor for the case where the deleted node has two children.
     *
     * @param id Unique 8-Digit ID number
     */
    void remove(const int id)
    {
        // TODO: implement
    }

    /**
     * @brief
     * Search for the student with the specified ID from the tree.
     * If the ID was found, print out their NAME.
     * If the ID does not exist within the tree, print “unsuccessful”.
     * @param id Unique 8-Digit ID number
     */
    void search(const int id)
    {
        // TODO: implement
    }

    /**
     * @brief
     * Search for the student with the specified name, NAME in the tree.
     * If the student name was found, print the associated ID.
     * If the tree has more than one object with the same NAME,
     * thenprint each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
     * If the name does not exist within the tree, print “unsuccessful”.
     * NAME identifier will be surrounded by double quotes for parsing, e.g. "Josh Smith".
     *
     * @param name Name of the student(s)
     */
    void search(const std::string name)
    {
        // TODO: implement
    }

    /**
     * @brief
     * Print out a comma separated in-order traversal of the names in the tree. LNR
     */
    void printInOrder()
    {
    }

    /**
     * @brief
     * Print out a comma separated pre-order traversal of the names in the tree. NLR
     */
    void printPreOrder()
    {
    }

    /**
     * @brief
     * Print out a comma separated post-order traversal of the names in the tree. LRN
     */
    void printPostOrder()
    {
    }

    /**
     * @brief
     * Prints the number of levels that exist in the tree.
     * Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has 4 levels.
     * AKA: Find max height of tree
     */
    void printLevelCount()
    {
    }

    /**
     * @brief
     * Remove the Nth GatorID from the in-order traversal of the tree (N = 0 for the first item, etc).
     * If removal is successful, print “successful”.
     * [Optional: Balance the tree automatically if necessary.
     * We will test your code only on cases where the tree will be balanced before and after the deletion.
     * So you can implement a BST deletion and still get full credit]
     * If the Nth GatorID does not exist within the tree, print “unsuccessful”.
     * @param n Nth Gator-ID from the IN-ORDER traversal
     */
    void removeInOrder(const int n)
    {
    }
};