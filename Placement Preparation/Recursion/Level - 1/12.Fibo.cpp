#include<bits/stdc++.h>
#define long long ll

using namespace std;

// find the nth Fibonacci number 
// Time Complexity: O(2 ^ n)
// Space Complexity : O(n)
int fibo(int n){
	if(n == 0 ){
		return 0;
	}
	if(n == 1){
		return 1;

	}

	return fibo(n - 1) + fibo(n - 2);
}
int main(){

	cout << fibo(13); 
	// output for 13 is 233

	return 0;
}
