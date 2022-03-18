#include<bits/stdc++.h>
#define long long ll
using namespace std;

bool isPalindrome(string s){
	int start = 0;
	int end = s.size() - 1;

	while(start < end){
		if(s[start] != s[end]){
			return false;
		}
		start++;
		end--;
	}
	return true;
}
void partitionPalindome(string str,  vector<string> &ans, vector<vector<string>> &finalOutput){
	if(str.size() == 0){
		// cout << "answerSoFar: " << answerSoFar << endl;
		finalOutput.push_back(ans);
		return;
	}

	for(int i = 0; i < str.size(); i++){
		string prefix = str.substr(0, i+1);
		// cout << "prefix: " << prefix << endl;
		string restOfString = str.substr(i + 1);

		if(isPalindrome(prefix)){
			ans.push_back(prefix);
			partitionPalindome(restOfString, ans, finalOutput);	
			ans.pop_back();
		}
	}
}
	
int main(){

	vector<string> ans;
	string str = "aabb";

	vector<vector<string>> finalOutput;
	partitionPalindome(str, ans, finalOutput);

	for(auto ans : finalOutput){
		for(auto palidromeString : ans){
			cout << palidromeString << " ";
		}
		cout << endl;
	}

	return 0;
}
