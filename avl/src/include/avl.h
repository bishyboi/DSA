#pragma once
#include <iostream>
#include <string>
//findHeight() should be recursive, returning the height of the next node +1
//findBalanceFactor() should be recursive, returning the sums of left and right heights

//left-right on  0, -1, 2

struct AVLTree{
    struct Node{
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        std::unique_ptr<Node> parent;

        std::unique_ptr<std::string> name;
        std::unique_ptr<int> gator_id;

        Node(std::unique_ptr<Node> l=nullptr , std::unique_ptr<Node> r=nullptr, std::unique_ptr<Node> p=nullptr, std::unique_ptr<std::string> name = nullptr, std::unique_ptr<int> id = nullptr)
        {
            this->left = move(l);
            this->right = move(r);
            this->parent = move(p);
            this->name = move(name);
            this->gator_id = move(id);
        }
    };
    
    std::unique_ptr<Node> root;

};