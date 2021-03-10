// 104. Maximum Depth of Binary Tree
// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.

#include <bits/stdc++.h>

using namespace std;

struct Node  {
  int val;
  Node* left;
  Node* right;
};

Node * CreateNode(int data) 
{ 
    Node* newNode = new Node();
    newNode->val = data; 
    newNode->left = NULL; 
    newNode->right = NULL; 
     
    return(newNode); 
} 

int maxDepth(Node* root) {
  if (!root) return 0;

  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    Node* root = CreateNode(3);
 
    root->left = CreateNode(9); 
    root->right = CreateNode(20);  
    root->right->left = CreateNode(15); 
    root->right->right = CreateNode(7); 
     
    cout << "Height of tree is " << maxDepth(root); 
}