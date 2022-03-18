#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinarySearchTree{
    public:
        T data;
        BinarySearchTree<T> *root; 
        BinarySearchTree<T> *left, *right;
    public:
        BinarySearchTree(){
            root = NULL;
        }

        BinarySearchTree(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        BinarySearchTree<int> *insert(BinarySearchTree<int> *root, int data){
            if(!root){
                return new BinarySearchTree<int>(data);
            }

            if(root -> data > data){
                root -> left = insert(root -> left, data);
            }
            else{
                root -> right = insert(root -> right, data);
            }

            return root;
        }

        BinarySearchTree<int> *insertIterative(BinarySearchTree<int> *root, int data){
            BinarySearchTree<int> *curr = root;
            BinarySearchTree<int> *parent = NULL;
            BinarySearchTree<int> *temp = new BinarySearchTree<int>(data);

            while(curr){
                parent = curr;
                if(curr -> data > data) curr = curr -> left;
                else curr = curr -> right; 
            }
            if(parent == NULL) return temp;
            else if(parent -> data > data) parent -> left = temp;
            else parent -> right = temp;

            return root;
        }
        void insert(int data){
            // this -> root = insert(root, data);
            this -> root = insertIterative(root, data);
        }

        BinarySearchTree<int>* deleteInBST(BinarySearchTree<int> *root, int data){
            if(!root) return root;

            if(root -> data > data){
                root -> left = deleteInBST(root -> left, data);
                return root;
            }
            else if(root -> data < data){
                root -> right = deleteInBST(root -> right, data);
                return root;
            }
            else{
                if(root -> left == NULL && root -> right == NULL){
                    delete root;
                    return NULL;
                }
                else if(root -> right == NULL){
                    BinarySearchTree<int> * temp = root -> right;
                    root -> right = NULL;
                    delete root;
                    return temp;
                }
                else if(root -> left == NULL){
                    BinarySearchTree<int> * temp = root -> left;
                    root -> left = NULL;
                    delete root;
                    return temp;
                }

                else{
                    BinarySearchTree<int> *temp = root -> right;
                    while(temp -> left != NULL){
                        temp = temp -> left;
                    }

                    int newRoot = temp -> data;
                    root -> data = newRoot;
                    root -> right = deleteInBST(root -> right, newRoot);
                    return root;
                }
            }

        }

        BinarySearchTree<int> *searchInBST(BinarySearchTree<int> * root, int data){
            if(!root) return root;

            if(root -> data > data){
                searchInBST(root -> left, data);
            }
            else if(root -> data < data){
                searchInBST(root -> right, data);
            }
            else{
                return root;
            }

        }
        void searchInBST(int data){
            BinarySearchTree<int> * temp = searchInBST(root, data);
            if(temp) cout << temp -> data << " present\n";
            else cout << "Not present\n";
        }
        void deleteInBST(int data){
            this -> root = deleteInBST(root, data);
        }

        void inorder(BinarySearchTree<int>*root, vector<int> &v){
            if(!root) return;
            inorder(root -> left, v);
            v.push_back(root -> data);
            inorder(root -> right, v);
        }
       vector<int> mergeTwoArray(vector<int> v1, vector<int> v2){
           int n1 = v1.size();
           int n2 = v2.size();
           int i = 0, j = 0, k = 0;
           vector<int> output;
           while(i < n1 && j < n2){
               if(v1[i] > v2[j]){
                   output.push_back(v2[j]);
                   j++;
               }
               else if(v1[i] <= v2[j]){
                   output.push_back(v1[i]);
                   i++;
               }
           }

           while(i < n1){
                output.push_back(v1[i++]);
           }
           while(j < n2){
                   output.push_back(v2[j++]);
           }

           return output;
       }
       BinarySearchTree<int> *constructBinarySearchTree(int low, int high, vector<int> &v){
           if(high < low) return NULL;

           int mid = (low + high)/2;

           BinarySearchTree<int> *temp = new BinarySearchTree<int>(v[mid]);

           temp -> left = constructBinarySearchTree(low, mid -1, v);
           temp -> right = constructBinarySearchTree(mid +1, high, v);
           return temp;
       }
       BinarySearchTree<int> *mergeTwoBST(BinarySearchTree<int> *root1, BinarySearchTree<int> *root2){
            vector<int> v1, v2;
            inorder(root1, v1);
            inorder(root2, v2);

            vector<int> output = mergeTwoArray(v1, v2);
      
           

            BinarySearchTree<int>*temp = constructBinarySearchTree( 0, output.size() - 1, output);
            this -> root = temp;
            // printTree();
            // cout << temp -> data << endl;
            return temp;
       }
            
        void printTree(){
            if(!root) return;
            queue<BinarySearchTree<int> *> q;

            q.push(root);

            while(q.size()){
                BinarySearchTree<int> *t = q.front();
                q.pop();
                cout << t->data << ": ";

                if(t -> left){
                    cout << "L " << t -> left -> data << " ";
                    q.push(t -> left);
                }

                if(t -> right){
                    cout << "R " << t -> right -> data << " ";
                    q.push(t -> right);
                }
                cout << endl;
            } 


        }   

        

     

        ~BinarySearchTree(){
            delete left;
            delete right;
        }


};

int main() {
    /* Construct below BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    BinarySearchTree<int> root;
    BinarySearchTree<int> t;
    root.insert(15);
    root.insert(10);
    root.insert(20);
    root.insert(8);
    root.insert(12);
    root.insert(16);
    root.insert(25);
    // root.printTree();

   BinarySearchTree<int> root2;
   root2.insert(7);
   root2.insert(3);
   root2.insert(11);
//    root2.printTree();


   t.root = t.mergeTwoBST(root.root, root2.root); 
   t.printTree();

   
 





    return 0;
}
