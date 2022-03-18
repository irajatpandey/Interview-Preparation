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
 
bool checkComplete(BinaryTree<int> *root){
     queue<BinaryTree<int> *> q;
     if(root == NULL) return true;

     q.push(root);

     while(!q.empty()) {
        BinaryTree<int> * t = q.front();
        q.pop();  
        if (t == NULL) {
            while (!q.empty()) {
                 if (q.front() != NULL)
                    return false;
                    q.pop();
                }
            return true;
            } 
            else {
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
      
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
   

    if(checkComplete(root))
        cout << "Yes\n";
    else
        cout << "No\n";    
    return 0;
}