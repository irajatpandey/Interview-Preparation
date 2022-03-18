#include<bits/stdc++.h>
#define long long ll
using namespace std;


void replaceSumWithLargerValue(BST *root){
	if(!root) return;

	replaceSumWithLargerValue(root -> right);
	replaceSumWithLargerValue(root -> left);

}
	
int main(){


	return 0;
}

