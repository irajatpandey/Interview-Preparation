#include <bits/stdc++.h>
using namespace std;
class BinaryTree {
public:
    int data;
    BinaryTree  *left, *right;

    BinaryTree(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }

};

void printDiagonalHelper(BinaryTree *root, int diagonal, unordered_map<int,vector<int>> &mp){
    if(!root) return;

    mp[diagonal].push_back(root -> data);

    printDiagonalHelper(root -> left, diagonal + 1, mp);
    printDiagonalHelper(root -> right, diagonal, mp);

    return;
}

void printDiagonal(BinaryTree *root){
    if(!root) return;

    unordered_map<int,vector<int>> mp;
    int diagonal = 0;

    printDiagonalHelper(root, diagonal, mp);

    for(auto it : mp){
        for(int val : it.second)
            cout << val << " ";
        cout << endl;
    }
}


int main() {

       /* Construct the following tree
               1
             /  \
            /    \
           2      3
          /     /  \
         /     /    \
        4     5     6
             / \
            /   \
           7     8
    */
 
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->right->left = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->right->left->left = new BinaryTree(7);
    root->right->left->right = new BinaryTree(8);
 
    printDiagonal(root);

    return 0;

}