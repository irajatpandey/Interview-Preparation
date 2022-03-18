#include<bits/stdc++.h>
#define long long ll
using namespace std;

void stringPermutations(string str, string answerSoFar){
	if(str.size() == 0){
		cout << answerSoFar << endl;
		return;
	}
	for(int i = 0; i < str.size(); i++){
		char ch = str[i];
		string leftString = str.substr(0, i); // ""
		string rightString = str.substr(i + 1); // BC
		string smallOutput = leftString + rightString;
		// cout << "leftString " << leftString << " ";
		// cout << "rightString " << rightString << " ";
		// cout << "smallOutput " << smallOutput << " ";
		// cout << endl;
		stringPermutations(smallOutput, answerSoFar + ch);


	}
}
int main(){

	string str = "ABC";
	string answerSoFar = "";

	stringPermutations(str, answerSoFar);
	return 0;
}
