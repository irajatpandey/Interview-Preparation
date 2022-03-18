#include<bits/stdc++.h>
#define long long ll
using namespace std;

int longestSubstringWithAllUniqueCharacter(string str) {

	int i = 0, j = 0, ans = 0;
	unordered_map<char,int> mp;

	while(j < str.size()){
		mp[str[j]]++;
		if(mp.size() > j - i + 1){
			j++;
		}

		else if(mp.size() == j - i + 1){
			ans = max(ans, j - i + 1);
			j++;
		}
		else if(mp.size() < j - i + 1){
			while(mp.size() < j - i + 1){
				mp[str[i]]--;
				if(mp[str[i]] == 0){
					mp.erase(str[i]);
				}
				i++;
			}
			j++;
		}


	}
	return ans;
}

int main() {

	string str = "pwwkew";
	int k = 3;

	cout << longestSubstringWithAllUniqueCharacter(str);

	return 0;
}
