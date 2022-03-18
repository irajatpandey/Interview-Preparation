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

        BinarySearchTree<int>* deleteInBST(BinarySearchTree<int> *node, int data){
            if(!node) return node;

            if(node -> data > data){
                node -> left = deleteInBST(node -> left, data);
                // return node;
            }
            else if(node -> data < data){
                node -> right = deleteInBST(node -> right, data);
                // return node;
            }
            else{
                if(node -> left == NULL && node -> right == NULL){
                    delete node;
                    return NULL;
                }
                else if(node -> left == NULL){
                    BinarySearchTree<int> *temp = node -> right;
                    node -> right = NULL;
                    delete node;
                    return temp;
                }
                else if(node -> right == NULL){
                     BinarySearchTree<int> *temp = node -> left;
                     node -> left = NULL;
                    delete node;
                    return temp;
                }

                else{
                    BinarySearchTree<int> *temp = node -> right;
                    while(temp -> left != NULL){
                        temp = temp -> left;
                    }

                    int newnode = temp -> data;
                    node -> data = newnode;
                    node -> right = deleteInBST(node -> right, newnode);
                    return node;
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
    // root.insert(12);
    // root.insert(1);
    

    root.printTree();

    root.deleteInBST(15);
    cout << endl;
    root.printTree();

    root.searchInBST(10);



    return 0;
}
