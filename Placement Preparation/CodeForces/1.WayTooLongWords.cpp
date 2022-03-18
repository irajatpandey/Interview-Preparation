#include<bits/stdc++.h>
#define long long ll
using namespace std;

	
int main(){

	int n;
	cin >> n;

	while(n--){
		string str; cin >> str;

		if(str.size() <= 10){
			cout << str << endl;
		}

		else{
			string ans = str[0]+to_string(str.size()-2)+str[str.size() - 1];
			cout << ans << endl;
		}
	}

	return 0;
}
