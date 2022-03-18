#include<bits/stdc++.h>
#define long long ll
using namespace std;


void deleteMiddle(stack<int> &s, int n, int current){
	if(s.empty() or current == n) return;

	int top = s.top(); s.pop();

	deleteMiddle(s, n, current + 1);

	if(current != n/2){
		s.push(top);
	}
}
	
int main(){
	stack<int> s;
 
    //push elements into the stack
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    int current = 0;
    deleteMiddle(s, s.size(),current);
    // 8 was the middle element so it has been removed.


 
    // Printing stack after deletion of the middle element.
    while (!s.empty())
    {
        int p = s.top();
        s.pop();
        cout << p << " ";
    }
    return 0;

}
