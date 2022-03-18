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

void maxWidth(BinaryTree *root, int level,unordered_map<int,int> &mp){
    if(!root) return;

    mp[level]++;

    maxWidth(root -> left, level + 1, mp);
    maxWidth(root -> right, level + 1, mp);


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
    
    unordered_map<int,int> mp;
    int ans = INT_MIN;
    maxWidth(root, 1, mp);
    for(auto it : mp){
        cout <<it.first << " " << it.second << endl;
        ans = max(ans,it.second);
    }
    cout << "ans " <<ans << endl;

    return 0;

}