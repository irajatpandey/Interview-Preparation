#include<bits/stdc++.h>
#define long long ll
using namespace std;
/* 

	T(n) = T(n-1) + n
	    = T(n-2) + (n-1) + n
	    = T(n-3) + (n-2) + (n-1) + n
	 
	and so on, until
	 
	T(n) = T(n-(n-1)) + T(n-(n-2)) + … + (n-2) + (n-1) + n
	    = T(1) + T(2) + … + (n-2) + (n-1) + n = n×(n+1)/2
	    = 1 + 2 + … + (n-2) + (n-1) + n = n×(n+1)/2
	    = O(n2)

*/

//The time complexity of the above solution is O(n ^ 2) and requires O(n) implicit space for the call
//stack, where n is the total number of elements in the stack. The recurrence relation is:
void insertAtBottom(stack<int> &st, int item){
	if(st.size() == 0){
		st.push(item);
		return;
	}

	 // Pop all items from the stack and hold them in the call stack
    int top = st.top();
    st.pop();
    insertAtBottom(st, item);


    // After the recursion unfolds, push each item in the call stack
    // at the top of the stack
    st.push(top);
 
}
void reverseStack(stack<int> &st){
	if(st.size() == 0){
		return;
	}


	int top = st.top();
	st.pop();

	reverseStack(st);

	// After the recursion unfolds, insert each item in the call stack
    // at the bottom of the stack
    insertAtBottom(st, top);;
}
	
int main(){


	stack<int> s;

	int arr[] = {5, 1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	stack<int> st;
	for(int i = 0; i < n; i++){
		st.push(arr[i]);
	}

	while(st.size() > 0){
		cout << st.top() << " ";
		st.pop();
	}


	for(int i = 0; i < n; i++){
		st.push(arr[i]);
	}
	cout << endl;
	reverseStack(st);

	while(st.size() > 0){
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}
