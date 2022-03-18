#include<bits/stdc++.h>
#define long long ll
using namespace std;

vector<string> keypadCombination(vector<string> keypad, string str){

	if(str.size() == 0){
		vector<string> result;
		result.push_back("");
		return result;

	}

	char first = str[0];
	string rest = str.substr(1);
	vector<string> smallOutput = keypadCombination(keypad, rest);

	vector<string> result;

	string desiredIndexString = keypad[first - '0'];

	for(int i = 0; i < desiredIndexString.length(); i++){
		for(auto it : smallOutput){
			result.push_back(desiredIndexString[i] + it);
		}
	}
	return result;
}
	
int main(){
	vector<string> keypad = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	string n = "23";
	vector<string> output = keypadCombination(keypad, n);
	for(auto it : output){
		cout << it << "\n";
	}

	return 0;
}
