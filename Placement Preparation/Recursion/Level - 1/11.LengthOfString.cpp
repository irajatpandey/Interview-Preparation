#include<bits/stdc++.h>
#define long long ll
using namespace std;

int length(string s, int &i){
	if(s.empty()){
		return 0;
	}
	i++;

	return 1 + length(s.substr(i), i);
}
	
int main(){
	int i = -1;
	cout << length("abc", i);
	return 0;
}
