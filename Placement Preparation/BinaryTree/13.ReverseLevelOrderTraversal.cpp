#include <bits/stdc++.h>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree  *left, *right;

    BinaryTree(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
    
};
int height(BinaryTree *root){
    if(!root) return 0;

    int leftHeight = height(root-> left);
    int rightHeight = height(root-> right);

    return max(leftHeight, rightHeight) + 1;
}


void printReverseLevelOrderTraversal(BinaryTree *root, int level){
    if(!root) return;
    // if(level < 0) return;
    if(level == 0){
        cout << root -> data << " ";
    }

   printReverseLevelOrderTraversal(root -> left, level - 1);
    // cout << "root -> data " << root -> data << endl;
   printReverseLevelOrderTraversal(root -> right, level - 1);
}
// Recursive 
void reverseLevelOrderTraversal(BinaryTree *root){
     if(!root) return;
    int h = height(root);

    for(int i = h; i >= 0; i--){
        printReverseLevelOrderTraversal(root, i);
        cout << endl;
    }

    return;
}


void reverseLevelOrderTraversal2(BinaryTree *root){
     queue<BinaryTree *> q;
     stack<BinaryTree *> s;

     if(!root) return;
     q.push(root);
     while(q.size() > 0){
         BinaryTree *t = q.front();

         if(t -> right){
             q.push(t -> right);
         }

         if(t -> left){
             q.push(t -> left);
         }

         s.push(t);
         q.pop();
     }

     while(s.size() > 0){
         cout << s.top() -> data << " ";
         s.pop();
     }
}
int main(){

    // binary tree formation 
    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(7);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    7  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /         */
    root->right->right = new BinaryTree(3); /*     6 1         */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);

    // reverseLevelOrderTraversal(root);
    reverseLevelOrderTraversal2(root);
    
    return 0;

}