#include<bits/stdc++.h>
#define long long ll
using namespace std;

// The idea is two take two pointer if the arr[i] != arr[j] then increment i and arr[i] = arr[j]
// if(arr[i] == arr[j]) j++

// Time Complexity : O(n)
// Space Complexity : O(1)
int removeDuplicate(int arr[], int n){
	    if(n < 1) return 1;
        int i = 0, j = 1;
        while(i < n && j < n){
            if(arr[i] == arr[j]){
                j++;
            }
            
            else{
            	i++;
              	arr[i] = arr[j];
              
            }
        }
       
        return i + 1;
}

void display(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
	
int main(){
   int arr[] = {1, 2, 3, 4, 13, 23, 24};
   int n = sizeof(arr)/sizeof(arr[0]);

   int size = removeDuplicate(arr, n);
   cout << size << endl;
   display(arr, size);
   
	return 0;
}
