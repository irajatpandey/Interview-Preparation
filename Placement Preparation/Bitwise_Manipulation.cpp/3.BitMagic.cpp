#include<bits/stdc++.h>
#define long long ll
using namespace std;

int getibits(int n, int i){
	int mask = (1 << i);

	return (n & mask) > 0 ? 1 : 0;
}
int setibits(int n, int i){
	int mask = (1 << i);

	return (n | mask);
}

int clearBit(int n, int i){
	int mask = (~(1 << i));
	int ans = (n & mask);
	return ans;
}

int main(){

	int n = 5;
	int i = 1;

	cout << getibits(n, i) << endl;
	cout << setibits(n, i) << endl;
	cout << clearBit(n, i) << endl;
	
}
// 0 0 0 0 1 0 0 0
// 0 0 0 0 1 0 0 0
//------------------- 
// 0 0 0 0 1 0 0 0