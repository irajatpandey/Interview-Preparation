#include<bits/stdc++.h>
#define long long ll
using namespace std;

	
int main(){

	int n; cin >> n;

	vector<int> v(n);
	int totalSum = 0, count = 0, half = 0, sum1 = 0;

	for (int i = 0; i < n; i++){
		cin >> v[i];
		totalSum += v[i];
	} 

	half = totalSum/2;

	sort(v.begin(), v.end(), greater<int>());

	for(int i = 0; i < n; i++){
		sum1 += v[i];
		count++;
		if(sum1 > half){
			break;
		}
	}

	cout << count << endl;

	return 0;
}
