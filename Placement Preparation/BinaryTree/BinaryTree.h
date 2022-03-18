#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
    public:
        BinaryTree *left, *right, *root;
        T data;
    public:
      BinaryTree(){
          root = NULL;
      }
      BinaryTree(T data){
          this -> data = data;
          left  = NULL;
          right = NULL;
      }
    
      void printTreeHelper1(BinaryTree<int> *root){
          if(!root) return;
          cout << root -> data << ": ";
          if(root -> left){
              cout << "L " << root->left->data << " ";
          }
          if(root -> right){
              cout << "R " << root->right->data << " ";
          }
          cout << endl;
          printTreeHelper1(root -> left); 
          printTreeHelper1(root -> right); 

      }

      void printTreeHelper2(BinaryTree<int> *root){
          if(root == NULL) return;
          queue<BinaryTree<int>*> q;

          q.push(root);

          while(q.size() > 0){
              BinaryTree<int> *front = q.front();
              q.pop();
              
              cout << front -> data << ": ";
              if(front -> left){
                  cout << "L " << front -> left -> data << " ";
                  q.push(front -> left);
              }
              if(front -> right){
                  cout << "R " << front -> right->data << " ";
                  q.push(front -> right);
              }
              cout << endl;
              
          }

          return;
      }
      void printTree(){
        //   printTreeHelper1(root);
          printTreeHelper2(root);
      }

      void takeInput(){
        //   if(!root) return;
          queue<BinaryTree<int>*> pendingNodes;

          cout << "Enter root data \n";
          int rootData; cin >> rootData;
          if(rootData == -1) return;
          root = new BinaryTree<int>(rootData);
          cout << root -> data << endl;
          pendingNodes.push(root);

          while(pendingNodes.size() > 0){
               BinaryTree<int> *front = pendingNodes.front();
               pendingNodes.pop();
               cout << "Enter left child of " << front -> data << endl;
               int leftChildData; cin >> leftChildData;

               if(leftChildData != -1){
                   BinaryTree<int> *child = new BinaryTree<int>(leftChildData);
                   front -> left = child;
                   pendingNodes.push(child);
               }
               
               cout << "Enter right child of " << front -> data << endl;
               int rightChildData; cin >> rightChildData;
               if(rightChildData != -1){
                   BinaryTree<int> *child = new BinaryTree<int>(rightChildData);
                   front -> right = child;
                   pendingNodes.push(child);
               }            
              
          }

      }

      ~BinaryTree(){
          delete left;
          delete right;
      }

};

// int main() {

//     BinaryTree<int> root;
//     //   8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    
//     // 4 2 5 7 1 2 3 -1 -1 6 -1 1 -1 -1 -1 -1 -1 -1 -1



//     root.takeInput();
//     root.printTree();
    


//     return 0;
// }