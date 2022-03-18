#include<bits/stdc++.h>
#define long long ll
using namespace std;

int countOccurenceOfAnagram(string str, string pattern) {
	unordered_map<char, int> mp;
	for (auto it : pattern) mp[it]++;
	int k = pattern.size();

	int count = mp.size(), ans = 0;
	int i = 0, j = 0;

	while (j < str.size()) {
		if (mp.find(str[j]) != mp.end()) {
			mp[str[j]]--;
			if (mp[str[j]] == 0) count--;
		}

		if (j - i + 1 < k) j++;
		else if (j - i + 1 == k) {
			if (count == 0) ans++;
			if (mp.find(str[i]) != mp.end()) {
				mp[str[i]]++;
				if (mp[str[i]] == 1) count++;
			}

			i++; j++;

		}	

		for(auto it : mp){
			cout << it.first << " " << it.second << endl;
		}
		cout << endl;

	}
	return ans;

}
int main() {

	string str = "forxxorfxdofr";
	string pattern = "for";

	cout << countOccurenceOfAnagram(str, pattern);

	return 0;
}
