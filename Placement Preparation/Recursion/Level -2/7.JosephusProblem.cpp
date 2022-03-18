#include<bits/stdc++.h>
#define long long ll
using namespace std;

int JosephusProblem(int n, int k){
	if(n == 1){
		return 0;
	}

	int x = JosephusProblem(n - 1, k);
	int y = (x + k) % n;
	// cout << "x " << x << " y " << y << " n "<< n << "\n";

	return y;
}

int JosephusProblemIterative(int n, int k){
	int res = 0;
    for(int i = 1; i <= n; ++i){
    	res = (res + k) % i;
    	// cout << res << " ";
    }
    return res + 1;
}
int main(){

	cout << endl;
	cout << JosephusProblem(5, 3) + 1<< endl;
	cout << JosephusProblemIterative(5, 3) << endl;



	return 0;
}
