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
// Time Complexity : O(n ^ 2)
int findMaxPathSum(BinaryTree* root, int &result){
    if(!root) return 0;

    int left = findMaxPathSum(root -> left, result);
    int right = findMaxPathSum(root -> right, result);

    result = max(result, root -> data);
    result = max(result, root -> data + left);
    result = max(result, root -> data + right);
    result = max(result, root -> data + left + right);

    return max(root -> data, root -> data + max(left, right));
}


int main() {
 /* Construct the following tree
            1
          /   \
         /     \
        2      10
       / \    /  \
     -1  -4  -5   -6
         /   / \
        3   7   4
             \
             -2
    */
 
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(10);
    root->left->left = new BinaryTree(-1);
    root->left->right = new BinaryTree(-4);
    root->right->left = new BinaryTree(-5);
    root->right->right = new BinaryTree(-6);
    root->left->right->left = new BinaryTree(4);
    root->right->left->left = new BinaryTree(7);
    root->right->left->right = new BinaryTree(4);
    root->right->left->left->right = new BinaryTree(-2);
 
    int result = INT_MIN;
    // cout << findMaxPathSum(root, result) << endl;
    cout << "The maximum path sum is " << result << endl;
 

    return 0;

}