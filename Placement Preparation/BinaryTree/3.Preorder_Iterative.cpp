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


void preOrder1(BinaryTree *root){
    if(!root) return;

    stack<BinaryTree*> s;
    s.push(root);
    while(s.empty() == false){
        cout << s.top() -> data << " ";
        root = s.top();
        s.pop();
        if(root -> right){
            s.push(root -> right);
        }
        
         if(root -> left){
            s.push(root -> left);
        }
    }
 
    
}

void preOrder2(BinaryTree *root){
    if(!root) return;
    stack<BinaryTree *> s;

    while(s.size() > 0 || root != NULL){

        if(root){
            s.push(root);
            cout << root -> data << " ";
            root = root -> left;
        }

        else{
            root = s.top();
            s.pop();
            root = root -> right;
            
        }
    }

}

int main(){

    // binary tree formation 
    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(7);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    7  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /        */
    root->right->right = new BinaryTree(3); /*     6  1         */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    preOrder2(root);



}