#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Insert the given key into the sorted stack while maintaining its sorted order.
// This is similar to the recursive insertion sort routine


/*The time complexity of the above solution is O(n^2) and requires O(n) implicit space for the call
stack, where n is the total number of elements in the stack.*/
void insertInSortedOrder(stack<int> &s, int key){

    // base case: if the stack is empty or
    // the key is greater than all elements in the stack
	if(s.size() == 0 || key > s.top()){
		s.push(key);
		return;
	}
	/* We reach here when the key is smaller than the top element */
 
    // remove the top element
	int top = s.top(); s.pop();

 // recur for the remaining elements in the stack
	insertInSortedOrder(s, key);

	// insert the popped element back into the stack
	s.push(top);

}
void sortStack(stack<int> &s){

    // base case: stack is empty
	if(s.size() == 0){
		return;
	}
  // remove the top element
	int top = s.top();
	s.pop();

 // recur for the remaining elements in the stack
	sortStack(s);

	cout << "s.size() " << s.size() << " " << top << endl;
// insert the popped element back into the sorted stack
	insertInSortedOrder(s, top);
}
int main(){
	stack<int> s;

	int arr[] = {5, 1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	stack<int> st;
	for(int i = 0; i < n; i++){
		st.push(arr[i]);
	}


	sortStack(st);

	while(st.size() > 0){
		cout << st.top() << " ";
		st.pop();
	}


	return 0;
}
