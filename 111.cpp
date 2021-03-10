// 111. Minimum Depth of Binary Tree
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
};

Node* CreateNode(int data) {
  Node* newNode = new Node();
  newNode->val = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return (newNode);
}

int m_depth = INT_MAX - 1;
void helper(Node* root, int depth) {
  if (!root) return;

  if (root->left == NULL && root->right == NULL) {
    if (depth < m_depth) m_depth = depth;
  }

  helper(root->left, depth + 1);
  helper(root->right, depth + 1);
}

int minDepth(Node* root) {
  if (!root) return 0;

  helper(root, 1);

  return m_depth;
}

int main() {
  Node* root = CreateNode(3);

  root->left = CreateNode(9);
  root->right = CreateNode(20);
  root->right->left = CreateNode(15);
  root->right->right = CreateNode(7);

  cout << "Depth of tree is " << minDepth(root);
}