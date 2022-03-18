#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinarySearchTree{
    private:
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

        BinarySearchTree<int>* leastCommonAncestor(BinarySearchTree<int> *root, int k1, int k2){
            if(!root) return root;

            if(k1 < root -> data and k2 < root ->data){
                leastCommonAncestor(root -> left, k1, k2);
            }
            else if(k1 > root -> data and k2 > root -> data){
                leastCommonAncestor(root -> right, k1, k2);
            }
            else{
                return root;
            }

          
        }

        void leastCommonAncestor(int k1, int k2){
            BinarySearchTree<int> *output = leastCommonAncestor(root, k1, k2);
            if(root){
                cout << "LCA of " << k1 << " and " << k2 << " is " << output -> data << endl;
            }
            else{
                cout << "Invalid Input!";
            }
            return;
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
    root.insert(15);
    root.insert(10);
    root.insert(20);
    root.insert(8);
    root.insert(12);
    root.insert(16);
    root.insert(25);
    root.printTree();

    root.leastCommonAncestor(20, 25);





    return 0;
}
