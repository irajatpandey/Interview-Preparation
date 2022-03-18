#include<bits/stdc++.h>
#define long long ll
using namespace std;

int sum(int n){

	if(n == 0){
		return 0;
	}

	return n % 10 + sum(n/10);
}
	
int main(){

	int n = 123;
	cout << sum(n) << endl;

	return 0;
}
