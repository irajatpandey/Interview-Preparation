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

// Time Complexity: O(N) 
// Auxiliary Space: O(N), where N is the total number of nodes in the tree.


void postorder(BinaryTree *root){
    if(!root) return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";


    return;
 
    
}
int main(){

    // binary tree formation 
    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(7);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    7  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      /          */
    root->right->right = new BinaryTree(3); /*     6           */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    postorder(root);



}