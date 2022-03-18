#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
	if(n == 0 || n == 1){
		return 1;
	}

	int smallOutput = factorial(n - 1);
	// cout << "smallOutput " << smallOutput << " " << "n " << n << endl;
	return smallOutput * n;

}
int main(){

	int n = 5;
	cout << factorial(n);

	return 0;
}