#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
    public:
    int data;
    BinaryTree<T> *left, * right;

    BinaryTree(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};
/*  Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
    Auxiliary Space: O(n), due to the stack space during recursive call. */
void printTopView(BinaryTree<int> *root, unordered_map<int, pair<int,int>> &mp, int level, int dist ){
    if(!root) return;

    if(mp.find(dist) == mp.end() || mp[dist].first > level ){
        mp[dist] = {level, root -> data};
    }

    printTopView(root -> left, mp, level + 1, dist - 1);
    printTopView(root -> right, mp, level + 1, dist + 1);
} 
void topView(BinaryTree<int> *root){

    if(root == NULL){ return; }

    unordered_map<int, pair<int,int>> mp;

    int dist = 0;
    int level = 1;

    printTopView(root, mp, level, dist);

    for(auto it : mp){
        cout << it.second.second << " ";
    }

   
}
BinaryTree<int> *takeInput(){
    cout << "Enter data ";
    int rootData; cin >> rootData;

    if(rootData == -1)
        return NULL;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    BinaryTree<int> *leftChild = takeInput();   
    BinaryTree<int> *rightChild = takeInput(); 
    root -> left = leftChild;
    root -> right = rightChild;
    return root;
}
void printTree(BinaryTree<int> *root){
    if(root == NULL) return;
    cout << root -> data << " : ";
    if(root -> left)
        cout << "L " << root -> left -> data << " ";
    if(root -> right)
        cout << "R " << root -> right -> data << " ";
    cout << endl;    
    printTree(root -> left);        
    printTree(root -> right);        
}
int main(){

    BinaryTree<int>* root = new BinaryTree<int>(4);      /*        4        */
    root->left = new BinaryTree<int>(2);                 /*       / \       */
    root->right = new BinaryTree<int>(5);                /*      2   5      */
    root->left->left = new BinaryTree<int>(7);           /*     / \ / \     */
    root->left->right = new BinaryTree<int>(1);          /*    7  1 2  3    */
    root->right->left = new BinaryTree<int>(2);          /*      / /        */
    root->right->right = new BinaryTree<int>(3);         /*     6 1         */
    root->left->right->left = new BinaryTree<int>(6); 
    root->right->left -> left = new BinaryTree<int>(1);
    topView(root);
    return 0;
}