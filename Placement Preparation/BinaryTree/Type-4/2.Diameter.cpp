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

int height(BinaryTree *root) {
    if (!root) return 0;

    int leftHeight = height(root-> left);
    int rightHeight = height(root-> right);

    return max(leftHeight, rightHeight) + 1;
}

int diameter1(BinaryTree *root) {
    if (!root) return 0;

    int option1 = height(root -> left) + height(root ->right) + 1;
    int option2 = diameter1(root -> left);
    int option3 = diameter1(root -> right);

    return max(option1, max(option2, option3));
}

pair<int, int> diameter2(BinaryTree *root) {
    if (!root) {
        pair<int, int> p{0, 0};
        return p;
    }

    pair<int, int> leftDiameter = diameter2(root -> left);
    pair<int, int> rightDiameter = diameter2(root -> right);
    pair<int, int> finalOutput;
    int lh = leftDiameter.first;
    int rh = rightDiameter.first;
    int ld = leftDiameter.second;
    int rd = rightDiameter.second;


    finalOutput.first = max(lh, rh) + 1;
    finalOutput.second = max(lh + rh + 1, max(ld, rd));
    cout <<"Data " << root -> data << " Height " << finalOutput.first << " " << "Diameter " << finalOutput.second << endl;
    return finalOutput;
}

int main() {

    // binary tree formation
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->right = new BinaryTree(4);
    root->right->left = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->right->left->left = new BinaryTree(7);
    root->right->left->right = new BinaryTree(8);


    // cout << "Height of Binary Tree is :" << height(root) << endl;
    cout << "Diameter of Binary Tree is :" << diameter1(root) << endl;
    cout << "Diameter of Binary Tree is :" << diameter2(root).second << endl;
    // cout << "Height of Binary Tree is :" << diameter2(root).first << endl;




    return 0;

}