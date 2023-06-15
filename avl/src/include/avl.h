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

        std::shared_ptr<Node> current = this->root;
        current->getID();
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
        std::shared_ptr insert = insertion;
        return insertOnNode(current, insert);
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
            if (current->right)
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
            if (current->left)
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

        if (beta)
        {
            beta->parent.reset();
            beta->parent = upper;
        }

        lower->right = upper;
        lower->parent = upper->parent;

        upper->left = beta;
        upper->parent = lower;

        // Reassigning the original upper's parent's child node so that everything is directed properly
        if (lower->parent)
        {
            if (lower->getID() < lower->parent->getID())
                lower->parent->left = lower;
            else
                lower->parent->right = lower;
        }
        else
        {
            this->root = lower;
        }

        lower->setBF(0);
        upper->setBF(0);
    }

    void rotateLeft(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        std::shared_ptr<Node> alpha = lower->left;

        if (alpha)
            alpha->parent = upper;

        lower->left = upper;
        lower->parent = upper->parent;

        upper->right = alpha;
        upper->parent = lower;

        // Reassigning the original upper's parent's child node so that everything is directed properly
        if (lower->parent)
        {
            if (lower->getID() < lower->parent->getID())
                lower->parent->left = lower;
            else
                lower->parent->right = lower;
        }
        else
        {
            this->root = lower;
        }

        lower->setBF(0);
        upper->setBF(0);
    }

    void rotateRightLeft(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        std::shared_ptr<Node> alpha = lower->left;
        std::shared_ptr<Node> alpha_l = alpha->left;
        std::shared_ptr<Node> alpha_r = alpha->right;

        // is this dropping alpha's previous children?? it looks like it
        // Shared pointers automatically reset on reassignment!!!
        alpha->parent = upper->parent;
        alpha->left = upper;
        alpha->right = lower;

        upper->parent = alpha;
        lower->parent = alpha;

        upper->right = alpha_l;
        lower->left = alpha_r;

        // Reassigning the original upper's parent's child node so that everything is directed properly
        if (alpha->parent)
        {
            if (alpha->getID() < alpha->parent->getID())
            {
                alpha->parent->left = alpha;
            }
            else
            {
                alpha->parent->right = alpha;
            }
        }
        else
        {
            this->root = alpha;
        }

        alpha->setBF(0);
        upper->setBF(0);
        lower->setBF(0);
    }

    void rotateLeftRight(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        std::cout << "peanuts";
        std::shared_ptr<Node> beta = lower->right;
        std::shared_ptr<Node> beta_l = beta->left;
        std::shared_ptr<Node> beta_r = beta->right;

        beta->parent = upper->parent;
        beta->left = lower;
        beta->right = upper;

        lower->right = beta_l;
        upper->left = beta_r;

        lower->parent = beta;
        upper->parent = beta;

        // Reassigning the original upper's parent's child node so that everything is directed properly
        if (beta->parent)
        {
            if (beta->getID() < beta->parent->getID())
            {
                beta->parent->left = beta;
            }
            else
            {
                beta->parent->right = beta;
            }
        }
        else
        {
            this->root = beta;
        }

        beta->setBF(0);
        lower->setBF(0);
        upper->setBF(0);
    }
    void retraceInsert(std::shared_ptr<Node> upper, std::shared_ptr<Node> lower)
    {
        // CHeck if the last ancestor (or the root) has been updated
        if (upper == nullptr)
            return;

        // Adjust the balance factor based on which side the subtree is on
        if (lower.get() == upper->left.get())
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
                rotateLeftRight(upper, lower);
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
                rotateRightLeft(upper, lower);
            }
        }

        // If the BF is +-1, then we need to keep retracing
        else if (upper->getBF() == 1 || upper->getBF() == -1)
        {
            if (upper->parent == nullptr)
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
     * You must prioritize replacing a removed node with its in-order successor for the case where
     * the deleted node has two children.
     * @param id Unique 8-Digit ID number
     */
    void remove(const int id)
    {
        std::shared_ptr<Node> search = this->root;

        // Step 1: Find the node to be removed (search)

        // Short-Circuit abusers (should avoid the getID() nullptr error by short-circuiting)
        while (search != nullptr || search->getID() != id)
        {
            if (search->getID() > id)
            {
                search = search->left;
            }
            else
            {
                search = search->right;
            }
        }

        // Step 2: Find search node's replacement

        // Check if the node actually exists
        if (!search)
        {
            return;
        }
        else
        {
            // Case 1: Search is a leaf node
            if (!(search->right || search->left))
            {
                if (search.get() != this->root.get())
                {
                    search->parent.reset();

                    if (search.get() == search->parent->right.get())
                    {
                        search->parent->right.reset();
                    }
                    else
                    {
                        search->parent->left.reset();
                    }
                }
                else
                {
                    // If it's the root node, and only node in tree, then we can just delete the root
                    this->root.reset();
                } 
                // The parent should be the only pointer on the node, with shared_ptr calling destructor
                // after this method falls out of scope
                return;
            }
            // Case 2: Search has only one child
            else if (!search->left || !search->right)
            {
                // Replace this node with its one child
                if (search->left)
                // Case: Search has only a left child
                {
                    // Edge case on root node
                    if (search.get() != this->root.get())
                    {
                        // If search is the right child of its parent
                        if (search.get() == search->parent->right.get())
                        {
                            search->parent->right = search->left;
                            search->left->parent = search->parent;
                        }
                        else
                        {
                            search->parent->left = search->left;
                            search->left->parent = search->parent;
                        }
                    }
                    else
                    {
                        this->root = search->left;
                    }
                }
                else
                // Case: Search has only a right child
                {
                    if (search.get() != this->root.get())
                    {
                        // If search is the right child of its parent
                        if (search.get() == search->parent->right.get())
                        {
                            search->parent->right = search->right;
                            search->right->parent = search->parent;
                        }
                        else
                        {
                            search->parent->left = search->right;
                            search->right->parent = search->parent;
                        }
                    }
                    else
                    {
                        this->root = search->right;
                    }
                }
                return;
            }
            // Case 3: Search has two children
            else
            {
                // We need to find the in-order successor, so we go right once, then left as much as possible
                std::shared_ptr<Node> replacement = search->right;

                while (replacement->left)
                    replacement = replacement->left;

                // Moving replacement to the search nodes position
                if (search.get() == this->root.get())
                    this->root = replacement;

                if (replacement->right)
                {
                    if (replacement.get() == replacement->parent->right.get())
                }

                else
                {
                    if (search.get() == search->parent->right.get())
                        search->parent->right = replacement;
                    else
                        search->parent->left = replacement;
                }

                // Rearranging replacement's children
            }
        }
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

    /**
     * @brief
     * Search for the student with the specified ID from the tree.
     * If the ID was found, print out their NAME.
     * If the ID does not exist within the tree, print “unsuccessful”.
     * @param id Unique 8-Digit ID number
     */
    std::string search(const int id)
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
    std::string search(const std::string name)
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
        if (current)
        {
            std::shared_ptr<Node> left = current->left;
            std::shared_ptr<Node> right = current->right;
            return current->getName() + ", " + printPreOrder(left) + printPreOrder(right);
        }
        else
        {
            return "";
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
        if (current)
        {
            std::shared_ptr<Node> left = current->left;
            std::shared_ptr<Node> right = current->right;
            return printPostOrder(left) + printPostOrder(right) + ", " + current->getName();
        }
        else
        {
            return "";
        }
    }

    /**
     * @brief
     * Prints the number of levels that exist in the tree.
     * Prints 0 if the head of the tree is null. For example, the tree in Fig. 1 has 4 levels.
     * AKA: Find max height of tree
     * @return int with the height of the tree
     */
    int getHeight()
    {
        return getHeight(this->root);
    }

    int getHeight(std::shared_ptr<Node> current)
    {
        if (!current)
        {
            return 0;
        }

        std::shared_ptr<Node> left = current->left;
        std::shared_ptr<Node> right = current->right;

        int height_L = 1 + getHeight(left);
        int height_R = 1 + getHeight(right);

        if (height_L > height_R)
            return height_L;
        else
            return height_R;
    }
};