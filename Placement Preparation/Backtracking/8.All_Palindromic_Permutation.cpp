#include<bits/stdc++.h>
#define long long ll
using namespace std;


void printAllPalindromicPermutation(int currentSpot ,int len, unordered_map<char,int> &mp, char oddc, string ansSoFar, vector<string> &ans){
	if(currentSpot > len){
		string rev = ansSoFar;
		// memcpy(ansSoFar, rev, ansSoFar.size());
		reverse(rev.begin(), rev.end());
		// cout << "ansSoFar: " << ansSoFar << endl;
		// cout << "rev " << rev << endl;
		string smallOutput = ansSoFar;
		if(oddc != '\0'){
			smallOutput += oddc;
		}
		smallOutput += rev;
		ans.push_back(smallOutput);
		return;
	}
	for(auto it : mp){
		int freq = it.second;
		char ch = it.first;
		if(freq > 0){
			mp[ch]--;
			printAllPalindromicPermutation(currentSpot + 1, len, mp, oddc, ansSoFar + ch, ans);
			mp[ch]++;
		}
	}
}
vector<string> all_permutations(string s){

	unordered_map<char,int> mp;
	vector<string> ans;
	for(auto it : s) mp[it]++;

	char oddc = '\0';
	int odds = 0;
	int len = 0;

	for(auto it : mp){
		int freq = it.second;
		if(freq % 2 == 1){
			oddc = it.first;
			odds++;
		}
		mp[it.first] = (freq)/2;
		len += freq/2;
	}
	
	int currentSpot = 1;
	// cout << "len " << len << endl;
	printAllPalindromicPermutation(currentSpot, len, mp, oddc, "", ans);

	return ans;
}	


int main(){

	string str = "abba";
	vector<string> ans = all_permutations(str);

	for(auto it : ans){
		cout << it << endl;
	}
	return 0;
}
