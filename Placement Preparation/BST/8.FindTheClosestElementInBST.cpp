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

       
        void insert(int data){
            this -> root = insert(root, data);
            // this -> root = insertIterative(root, data);
        }

        void minDifference(BinarySearchTree<int> *node, int k, int &ans){
            if(!node) return;

            ans = min(ans, abs(node -> data - k));
            if(node -> data < k)
                minDifference(node -> right, k, ans);
            else 
                minDifference(node -> left, k, ans);
        }
        int minDifference(int k){
            
            int ans = INT_MAX;
            minDifference(root, k, ans);
            cout << ans << endl;
            return ans;
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
    // root.printTree();

    cout << root.minDifference(9);
}
