#include<bits/stdc++.h>
#define long long ll
using namespace std;


void wordBreakHelper(string s, string ansSoFar, set<string> &dict, vector<string> &ans){

	if(s.size() == 0){
		// cout << ansSoFar << endl;
		ans.push_back(ansSoFar);
		return;
	}

	for(int i = 0; i < s.size(); i++){
		string left = s.substr(0, i + 1);
		if(dict.find(left) != dict.end()){
			string right = s.substr(i + 1);
			wordBreakHelper(right, ansSoFar + left + " ", dict, ans);
		}
	}
}

vector<string> wordBreak(string s, set<string> dict){

	vector<string> ans;
 	string ansSoFar = "";
	wordBreakHelper(s, ansSoFar, dict, ans);
	return ans;
}
int main(){

	string s = "microsofthiring";
	vector<string> words = {"micro", "soft", "hiring", "hi", "ring", "microsoft"};
	set<string> dict;
	for(auto wrd : words){
		dict.insert(wrd);
	}

	vector<string> ans = wordBreak(s, dict);
	for(auto it : ans){
		cout << it << endl;
	}

	return 0;
}
