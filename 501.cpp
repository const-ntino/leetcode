// 501. Find Mode in Binary Search Tree
// Given the root of a binary search tree (BST) with duplicates, return all the
// mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal
// to the node's key.
// The right subtree of a node contains only nodes with keys greater than or
// equal to the node's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
 public:
  int prev = INT_MIN, atual = 1, max = 0;

  void inOrder(TreeNode* root, vector<int>& resposta) {
    if (!root) return;
    if (root->left) inOrder(root->left, resposta);

    if (prev == INT_MIN)
      prev = root->val;
    else {
      if (prev == root->val)  // valor duplicado
        atual++;
      else
        atual = 1;
    }
    if (atual > max) {  // novo valor com frequência maior
      resposta.clear();
      resposta.push_back(root->val);
      max = atual;
    } else if (atual == max)  // mais de um valor duplicado
      resposta.push_back(root->val);

    prev = root->val;

    if (root->right) inOrder(root->right, resposta);
  }

  vector<int> findMode(TreeNode* root) {
    vector<int> resposta;
    inOrder(root, resposta);
    return resposta;
  }
};