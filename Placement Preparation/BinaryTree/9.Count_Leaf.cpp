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

int countLeaf(BinaryTree *root){
    if(!root){return 0;}

    if(root -> left == NULL && root -> right == NULL){
       return 1;
    }
    
    return countLeaf(root -> left) + countLeaf(root -> right);
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

    cout << countLeaf(root);
    
    return 0;

}