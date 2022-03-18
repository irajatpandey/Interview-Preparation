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

int maxSumRootToLeaf(BinaryTree* root){
    if(!root) return 0;

    int option1 = maxSumRootToLeaf(root -> left);
    int option2 = maxSumRootToLeaf(root -> right);

    int ans = max(option1, option2) + root -> data;
    // cout << ans << endl;
    return ans;
}   


int main() {

   /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        8   4   5   6
           /   / \   \
         10   7   9   5
    */
 
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(8);
    root->left->right = new BinaryTree(4);
    root->right->left = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->left->right->left = new BinaryTree(10);
    root->right->left->left = new BinaryTree(7);
    root->right->left->right = new BinaryTree(9);
    root->right->right->right = new BinaryTree(5);
    
    cout << maxSumRootToLeaf(root);

    return 0;

}