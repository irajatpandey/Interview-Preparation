#include<bits/stdc++.h>
#define long long ll
using namespace std;

bool isPowerOf2(int n){

	if(n == 0) return false;

	return n & n - 1;
}
int main(){

	int n = 16;

	bool flag = isPowerOf2(n);

	if(flag == 0) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
