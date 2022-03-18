#include<bits/stdc++.h>
#define long long ll
using namespace std;


string ans = "";

void findMaxInKSwap(string str, int k){

	if(k == 0){
		return;
	}

	for(int i = 0; i < str.size(); i++){
		for(int j = i + 1; j < str.size(); j++){
			if(str[j] > str[i]){
				swap(str[i], str[j]);
				if (str.compare(ans) > 0) ans = str;
				findMaxInKSwap(str, k - 1);
				swap(str[i], str[j]);

			}
		}
	}
	
}
	
int main(){

	// findMaxInKSwap("129814999", 4);
	findMaxInKSwap("9532", 2);

	cout << ans << endl;

	// 999984211 output
	return 0;
}
