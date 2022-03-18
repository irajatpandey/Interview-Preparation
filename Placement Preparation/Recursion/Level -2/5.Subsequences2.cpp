5#include<bits/stdc++.h>
#define long long ll
using namespace std;

//Time Complexity : O(2 ^ n)

void subs(string str, string output){
	if(str.size() == 0){
		cout << output << endl;
		return;
	}

	subs(str.substr(1), output);
	subs(str.substr(1), output + str[0]);

}
	
int main(){

	subs("abc", "");

	

	return 0;
}
