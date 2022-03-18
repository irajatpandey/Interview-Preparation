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

        BinarySearchTree<int>* constructBalancedBinarySearchTree2(int *arr, int low, int high){
            if(high < low) {
                return NULL;
            }

         

            int mid = (low + high)/2;

            BinarySearchTree<int> *temp = new BinarySearchTree<int>(arr[mid]);
            cout << arr[mid] << endl;
            temp -> left = constructBalancedBinarySearchTree2(arr, low, mid - 1);
            temp -> right = constructBalancedBinarySearchTree2(arr, mid + 1, high);

            return temp;
        }


        void constructBalancedBinarySearchTree(int *arr, int n){

            this -> root = constructBalancedBinarySearchTree2(arr, 0, n - 1);
            return;
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
    int arr[] = {8, 10, 12, 15, 16, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "n " << n << endl;


    root.constructBalancedBinarySearchTree(arr, n);
    root.printTree();



    return 0;
}
