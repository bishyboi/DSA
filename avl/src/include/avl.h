#pragma once
#include <iostream>
#include <string>
#include <memory>
// findHeight() should be recursive, returning the height of the next node +1
// findBalanceFactor() should be recursive, returning the sums of left and right heights

/**
 * Every time a node is inserted, the height of all parent nodes should be adjusted (add one if its the left node, subtract if its the right node)
 *
 */

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
        std::unique_ptr<int> balance_factor = std::make_unique<int>(0);

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
            this->balance_factor.reset();
        }

        std::string getName()
        {
            return *(this->name);
        }

        int getID()
        {
            return *(this->gator_id);
        }

        int getBF()
        {
            return *(this->balance_factor);
        }

        void setBF(int x)
        {
            *(this->balance_factor) = x;
        }

        void addBF(int x)
        {
            *(this->balance_factor) = this->getBF() + x;
        }
    };

    std::shared_ptr<Node> root = nullptr;

    /**
     * @brief Construct a new AVLTree object
     */
    AVLTree() {}

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
     * @return True if the node to be inserted does not already exist.
     * @return False if the node to be inserted already exists, in which nothing is inserted
     */
    bool insert(const std::string name, const int id)
    {
        std::shared_ptr<Node> insertion = std::make_shared<Node>(name, id);

        if (this->root == nullptr)
        {
            this->root = insertion;
            return true;
        }

        std::shared_ptr current = this->root;

        return insertOnNode(current, insertion);
    }

    /**
     * @brief
     * Inserts a node into the AVL tree
     * @param insertion Node to be inserted
     * @return True if the node to be inserted does not already exist.
     * @return False if the node to be inserted already exists, in which nothing is inserted
     */
    bool insert(std::shared_ptr<Node> insertion)
    {
        if (this->root == nullptr)
        {
            this->root = insertion;
            return true;
        }

        std::shared_ptr current = this->root;

        return insertOnNode(current, insertion);
    }

    /**
     * @brief Inserts a node into the AVL tree, targeting a specific node and its subtrees
     *
     * @param current is the node to begin looking at for insertion
     * @param insertion is the node that is being inserted
     * @return True if the node does not already exist
     * @return False if the node is already in the AVL tree, in which nothing is inserted
     */
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
                current->right = insertion;
                current->right->parent = current;

                retraceInsert(current, current->right);

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
                current->left = insertion;
                current->left->parent = current;

                retraceInsert(current, current->left);

                return true;
            }
        }
    }

    /**
     * @brief Rotates an upper and lower node left and right
     *
     * @param upper
     * @param lower
     */
    void rotateRight(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        std::shared_ptr<Node> beta = lower->right;

        lower->right.reset();
        beta->parent.reset();
        upper->left.reset();

        upper->left = beta;
        beta->parent = upper;
        lower->right = upper;

        lower->setBF(0);
        upper->setBF(0);
    }

    void rotateLeft(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        std::shared_ptr<Node> alpha = lower->left;

        //FIXME: SegFault when these are nullptrs, just add checks for nullptrs and this *should* be fixed
        lower->left.reset();
        alpha->parent.reset();
        upper->right.reset();
        // error on reassignment of shared pointer
        upper->right = alpha;
        alpha->parent = upper;
        lower->left = upper;

        lower->setBF(0);
        upper->setBF(0);
    }

    void retraceInsert(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        // CHeck if the last ancestor (or the root) has been updated
        // if (upper == nullptr)
        //     return;

        // Adjust the balance factor based on which side the subtree is on
        if (lower == upper->left)
        {
            upper->addBF(1);
        }
        else
        {
            upper->addBF(-1);
        }

        // If the BF after insertion is 0 at any node, then the height has remained the same
        if (upper->getBF() == 0)
        {
            return;
        }

        // If the BF is +- 2, then a rotation is needed
        else if (upper->getBF() == 2)
        {
            if (lower->getBF() == 1)
            {
                rotateRight(upper, lower);
            }
            else
            {
                rotateLeft(lower, lower->right);
                rotateRight(upper, lower->right);
            }
        }
        else if (upper->getBF() == -2)
        {
            if (lower->getBF() == -1)
            {
                rotateLeft(upper, lower);
            }
            else
            {
                rotateRight(lower, lower->left);
                rotateLeft(upper, lower->left);
            }
        }

        // If the BF is +-1, then we need to keep retracing
        else if (upper->getBF() == 1 || upper->getBF() == -1)
        {
            if(upper->parent == nullptr)
                return;
            else
                return retraceInsert(upper->parent, upper);
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
     * @return String containing the list of nodes in order
     */
    std::string printInOrder()
    {
        std::string printString = printInOrder(this->root);

        printString.erase(0, 2);
        printString.erase(printString.length() - 2, 2);
        return printString;
    }

    /**
     * @brief
     * Prints out a comma separated in-order traversal of the names in the tree, starting at a certain node
     * @param current Starting node to begin the in-order traversal
     * @return String containing the list of nodes in order
     */
    std::string printInOrder(std::shared_ptr<Node> current)
    {
        if (current == nullptr)
        {
            return "";
        }
        else if (current->left == nullptr && current->right == nullptr)
        {
            return current->getName();
        }
        else
        {
            return printInOrder(current->left) + ", " + current->getName() + ", " + printInOrder(current->right);
        }
    }

    /**
     * @brief
     * Print out a comma separated pre-order traversal of the names in the tree. NLR
     * @return String containing the names of students from a pre-order traversal
     */
    std::string printPreOrder()
    {
        std::string printString = printPreOrder(this->root);

        printString.erase(printString.length() - 2, 2);
        return printString;
    }

    /**
     * @brief
     * Prints out a comma separated pre-order traversal of the names in the tree, starting at a certain node
     * @param current Starting node to begin the pre-order traversal
     * @return String containing the list of nodes in pre-order
     */
    std::string printPreOrder(std::shared_ptr<Node> current)
    {
        if (current == nullptr)
        {
            return "";
        }
        else if (current->left == nullptr && current->right == nullptr)
        {
            return current->getName();
        }
        else
        {
            return current->getName() + ", " + printPreOrder(current->left) + ", " + printPreOrder(current->right);
        }
    }

    /**
     * @brief
     * Print out a comma separated post-order traversal of the names in the tree. LRN
     * @return Stromg containing the list of students from a post-order traversal
     */
    std::string printPostOrder()
    {
        std::string printString = printPostOrder(this->root);

        printString.erase(0, 2);
        return printString;
    }

    /**
     * @brief
     * Prints out a comma separated post-order traversal of the names in the tree, starting at a certain node
     * @param current Starting node to begin the post-order traversal
     * @return String containing the list of nodes in post-order
     */
    std::string printPostOrder(std::shared_ptr<Node> current)
    {
        if (current == nullptr)
        {
            return "";
        }
        else if (current->left == nullptr && current->right == nullptr)
        {
            return current->getName();
        }
        else
        {
            return printPostOrder(current->left) + ", " + printPostOrder(current->right) + ", " + current->getName();
        }
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