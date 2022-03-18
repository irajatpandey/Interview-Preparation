#include<bits/stdc++.h>
#define long long ll
using namespace std;
void rearrange(long long *arr, int n){
	int maxIndex = n - 1;
	int minIndex = 0;

	int maxEle = arr[n - 1] + 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			arr[i] += (arr[maxIndex] % maxEle) * maxEle;
			maxIndex--;
		}
		else {
			arr[i] += (arr[minIndex] % maxEle) * maxEle;
			minIndex++;
		}
	}
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] / maxEle;

}

int main() {


	return 0;
}
