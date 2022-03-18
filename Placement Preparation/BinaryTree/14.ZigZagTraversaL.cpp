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


void zigZagTraversal(BinaryTree *root){
    if(!root) return;
    stack<BinaryTree *> mainStack;
    stack<BinaryTree *> tempStack;
    mainStack.push(root);
    int level = height(root);
    bool LeftToRight = true;

    while(mainStack.size() > 0){
        BinaryTree *temp = mainStack.top();
        mainStack.pop();

        if(temp){
            cout << temp -> data << " ";
            if(LeftToRight){
                if(temp -> left){
                    tempStack.push(temp -> left);
                }
                if(temp -> right){
                    tempStack.push(temp -> right);
                }
            }
            else{
                if(temp -> right){
                    tempStack.push(temp -> right);
                }
                if(temp -> left){
                    tempStack.push(temp -> left);
                }
            }

        }

        if(mainStack.size() == 0){
            LeftToRight = !LeftToRight;
             swap(mainStack, tempStack);

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
    root->right->left = new BinaryTree(2);  /*      / /         */
    root->right->right = new BinaryTree(3); /*     6 1         */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);


    zigZagTraversal(root);


    
    return 0;

}