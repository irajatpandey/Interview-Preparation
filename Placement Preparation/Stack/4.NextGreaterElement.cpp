#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement1(int *arr, int n){
    vector<int> output;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]){
                output.push_back(arr[j]);
                break;
            }
        }
    }
    return output;
}


vector<int> nextGreaterElement2(int *arr, int n){
    vector<int> output;
    stack<int> s;

    for(int i = n - 1; i >= 0; i--){
        if(s.size() == 0) output.push_back(-1); 
        
        if(s.size() > 0 and s.top() > arr[i]){
            output.push_back(s.top());
        }
        else if(s.size() > 0 and s.top() <= arr[i]){
			while(s.size() > 0 and s.top() <= arr[i]){
                 s.pop();
            }
 
			if(s.size() == 0) output.push_back(-1);
			else output.push_back(s.top());
		}
    

        s.push(arr[i]);

    }
    // reverse(output.begin(), output.end());
    return output;
}


int main() {

    int arr[] = {1, 3, 0, 0, 1, 2, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> output = nextGreaterElement2(arr, n);
	
	reverse(output.begin(), output.end());
 	cout << "Output vector : ";
	for(auto it : output) cout << it << " ";



    return 0;
}