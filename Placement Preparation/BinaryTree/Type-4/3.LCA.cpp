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

// Naive Approach

bool findPath(BinaryTree *root, vector<BinaryTree *> &aux, int x) {
    if (!root) return false;
    aux.push_back(root);

    if (root -> data == x) {
        return true;
    }


    if (findPath(root -> left, aux, x) || findPath(root -> right, aux, x))
        return true;

    aux.pop_back();
    return false;
}

BinaryTree* LCA1(BinaryTree *root, int x, int y) {
    vector<BinaryTree*> path1, path2;

    if (findPath(root, path1, x) == false or findPath(root, path2, y) == false) {
        return NULL;
    }

    // for(auto it : path1) cout << it -> data << " ";
    // cout << endl;
    // for(auto it : path2) cout << it -> data << " ";

    int i = 0;
    for (i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
        if (path1[i + 1] != path2[i + 1])
            return path1[i];


    return path1[i];
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool isNodePresent(BinaryTree* root, int node)
{
    // base case
    if (root == nullptr) {
        return false;
    }
 
    // if the node is found, return true
    if (root -> data == node) {
        return true;
    }
 
    // return true if a given node is found in the left or right subtree
    return isNodePresent(root->left, node) ||
            isNodePresent(root->right, node);
}
 


// Assume that both the node x and y are present if anyone of them will be absent the code won't work
// The time complexity of the above solution is O(n), where n is the total number of nodes in the
//binary tree. The program requires O(h) extra space for the call stack, where h is the height of the tree.
BinaryTree *LCA2(BinaryTree *root, int x, int y){
    if(!root) return root;

    if(root -> data == x or root -> data == y){
        return root;
    }

    BinaryTree *LeftSubTree = LCA2(root -> left, x, y);
    BinaryTree *RightSubTree = LCA2(root -> right, x, y);

    if(LeftSubTree != NULL and RightSubTree != NULL){
        return root;
    }

    if(LeftSubTree != NULL){
        return LeftSubTree;
    }
    else{
        return RightSubTree;
    }

}
int main() {

    /* Construct the following tree
            1
          /   \
         /     \
        2       3
         \     / \
          4   5   6
             / \
            7   8
      */

    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->right = new BinaryTree(4);
    root->right->left = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->right->left->left = new BinaryTree(7);
    root->right->left->right = new BinaryTree(8);

    



    // cout << LCA1(root, 4, 5) -> data << endl;
    // cout << LCA1(root, 6, 7) -> data << endl;
    // cout << LCA1(root, 5, 8) -> data << endl;
   BinaryTree *ans = LCA1(root, 5, 8);
   if(ans == NULL){
    cout << "NULL \n";
   }
   else{
    cout << ans -> data << endl;
   }
   if(isNodePresent(root, 5) && isNodePresent(root, 8))
      cout << LCA2(root, 5, 8) -> data << endl;

   if(isNodePresent(root, 6) && isNodePresent(root, 7))
      cout << LCA2(root, 6, 7) -> data << endl;


    return 0;

}