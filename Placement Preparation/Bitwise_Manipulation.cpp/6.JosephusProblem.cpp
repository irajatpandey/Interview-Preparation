//Josephus Problem Using Bit Magic
/* */
#include<bits/stdc++.h>
#define long long ll
using namespace std;

int powerOf2(int n){
	int i = 1;
	while(i * 2 <= n){
		i = 2 * i;
	}
	// cout << i << endl;
	return i;
}
int JosephusProblem(int n){
	int l = n - powerOf2(n);

	return (2 * l + 1);
}
	
int main(){

	// int n; cin >> n;
	cout << JosephusProblem(5);

	return 0;
}
