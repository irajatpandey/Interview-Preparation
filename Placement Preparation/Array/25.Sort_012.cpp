#include<bits/stdc++.h>
#define long long ll
using namespace std;

void sort012(vector<int> &arr){
	int n = arr.size();
	int j = 0, k = n - 1;
	int i = 0;
	while(i <= k){
		if(arr[i] == 0){
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else if(arr[i] == 1){
			i++;
		}
		else if(arr[i] == 2){
			swap(arr[i], arr[k]);
			k--;
		}
	}

}	

void printArra

int main(){

	vector<int> arr = {1, 1, 2, 2, 0, 1, 2, 2, 0, 1, 2, 0, 2, 1};
	int n = arr.size();

	sort012(arr);

	for(auto it : arr){
		cout << it << " ";
	}
	return 0;
}
