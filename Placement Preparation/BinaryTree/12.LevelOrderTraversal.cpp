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


void printLevelOrderTraversal(BinaryTree *root, int level){
    if(!root) return;
    // if(level < 0) return;
    if(level == 0){
        cout << root -> data << " ";
    }

    printLevelOrderTraversal(root -> left, level - 1);
    // cout << "root -> data " << root -> data << endl;
    printLevelOrderTraversal(root -> right, level - 1);
}

void levelOrderTraversal(BinaryTree *root){
     if(!root) return;
    int h = height(root);

    for(int i = 0; i <= h; i++){
        printLevelOrderTraversal(root, i);
        cout << endl;
    }

    return;
}

void levelOrderTraversal2(BinaryTree *root){
    if(!root) return;
    queue<BinaryTree *> q;

    q.push(root);

    while(q.size() > 0 && root){
        BinaryTree *t = q.front();
        cout << t -> data << " ";
        q.pop();

        if(t -> left){
            q.push(t -> left);
        }
        if(t -> right){
            q.push(t -> right);
        }
        // cout << endl;
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

    levelOrderTraversal2(root);
    
    return 0;

}