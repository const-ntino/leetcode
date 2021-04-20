
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

