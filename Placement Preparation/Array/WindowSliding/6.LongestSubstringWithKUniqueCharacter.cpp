#include<bits/stdc++.h>
#define long long ll
using namespace std;

int longestSubstringWithKUniqueCharacter(string str, int k) {

	int i = 0, j = 0, ans = 0;
	unordered_map<char,int> mp;

	while(j < str.size()){
		mp[str[j]]++;
		if(mp.size() < k){
			j++;
		}

		else if(mp.size() == k){
			ans = max(ans, j - i + 1);
			j++;
		}
		else if(mp.size() > k){
			while(mp.size() > k){
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

	string str = "aabacbebebe";
	int k = 3;

	cout << longestSubstringWithKUniqueCharacter(str, k);

	return 0;
}
