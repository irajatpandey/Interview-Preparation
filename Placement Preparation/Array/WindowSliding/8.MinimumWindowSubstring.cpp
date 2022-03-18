#include<bits/stdc++.h>
#define long long ll
using namespace std;


string minimumWindowSubstring(string s, string t) {
	unordered_map<char, int> mp;
	for (auto it : t) {
		mp[it]++;
	}
	pair<int, int> p;

	int count = mp.size();
	int i = 0, j = 0, min = INT_MAX;

	while (j < s.size()) {

		if (mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;

			if (mp[s[j]] == 0) {
				count--;
			}
			j++;
		}
		else j++;


		if (count == 0) {
			while (count == 0) {
				if (j - i < min) {
					min = j - i;
					p.first = i;
					p.second = j;
				}
				if (mp.find(s[i]) != mp.end()) {
					mp[s[i]]++;
					if (mp[s[i]] > 0) {
						count++;
					}
					i++;
				}
				else i++;
			}

		}
	}

		string ans = "";
		i = p.first;
		j = p.second;
		while (i < j) {
			ans += s[i++];
		}

		return ans;
	}
	int main() {

		string s = "ADOBECODEBANC", t = "ABC";
		string ans = minimumWindowSubstring(s, t);
		cout << ans;
		return 0;
	}
