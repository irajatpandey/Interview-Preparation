#include<bits/stdc++.h>
#define long long ll
using namespace std;

vector<string> subs(string str){
	if(str.size() == 0){
		vector<string> output;
		output.push_back("");
		return output;
	}
	char firstChar = str[0];
	vector<string> smallOutput = subs(str.substr(1)); // It will bring the output for "bc" 

	// Now we have to add the "a" to the our output to get the desired result
	vector<string> output;
	for(auto it : smallOutput){
		output.push_back(it);  
	}
	for(auto it : smallOutput){
		output.push_back(firstChar + it);
	}

	return output;
}
	
int main(){

	vector<string> ans = subs("abc");

	for(auto it : ans){
		cout << it << "\n";
	}


	return 0;
}
