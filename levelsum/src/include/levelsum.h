#pragma once
#include <iostream>

 class TreeNode 
 {
    public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

// This will be called in main to construct the tree
TreeNode* insert(TreeNode* root, int data) 
{
  if (root == nullptr)
    return new TreeNode(data);
  if (root->val < data)
    root->right = insert(root->right, data);
  else 
    root->left = insert(root->left, data);
  return root;
}

// This will be called in main to deallocate memory
void destruct(TreeNode* root) 
{
  if (root->left) 
    destruct(root->left);
  if (root->right) 
    destruct(root->right);
  delete root;
}

int sumOfLevel(TreeNode* root, int level) 
{
    TreeNode* parent = root;

    if(parent == nullptr)
        return 0;
    
    
}
