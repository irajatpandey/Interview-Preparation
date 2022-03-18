#include<bits/stdc++.h>
#define long long ll
using namespace std;
string generateSequence(int n){
	int temp = n; 
	string s = "";
	while(temp > 0){
		// cout << temp;
		s += to_string(temp);
		temp--;
	}	
	reverse(s.begin(), s.end());
	return s;
}

// Naive Approach
// The main idea is to generate all the permutation and store it into the vector of string and return the k-1 value
void kthPermutation1(string s, string answerSoFar, vector<string> &ans){
	// base case
	if(s.size() == 0){
		ans.push_back(answerSoFar);
		return;
	}

	for(int i = 0; i < s.size(); i++){
		char ch = s[i];
		string leftString = s.substr(0, i);
		string rightString = s.substr(i + 1);
		string finalString = leftString + rightString;
		kthPermutation1(finalString, answerSoFar + ch, ans);

	}

	return;	
}

string kthPermutation2(int n, int k){
	int fact = 1;
	vector<int> numbers;

	for(int i = 1; i < n; i++){
		fact = fact * i;
		numbers.push_back(i);
	}


	numbers.push_back(n);


	k = k - 1;

	string ans = "";
	while(true){
		ans += to_string(numbers[k/fact]);
		numbers.erase(numbers.begin() +k/fact);
		if(numbers.size() == 0) 
			break;

		k = k % fact;
		fact = fact / numbers.size();
	}
	return ans;
}



int main(){

	vector<string> ans;
	string answerSoFar = "";
	int n = 3;
	int k = 3;

	// string s = generateSequence(n); // if n = 3, seq -> 123
									// if n = 4. seq -> 1234						
	// kthPermutation1(s, answerSoFar, ans);

	// sort(ans.begin(), ans.end()); // ans should be in lexicographically order

	// cout << ans[k - 1] << endl;

	cout << kthPermutation2(n, k);


	return 0;
}
