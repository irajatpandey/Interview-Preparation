#include<bits/stdc++.h>
#define long long ll
using namespace std;

void displayArray(int arr1[], int m, int arr2[], int n){
	for (int i = 0; i < m; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

}

// Time Complexity : ((m+n)log(m+n))
// Space Complexity : O(m + n)
void mergeTwoSortedArray1(int arr1[], int m, int arr2[], int n) {
	int *arr3 = new int[m + n];

	for (int i = 0; i < m; i++) {
		arr3[i] = arr1[i];
	}

	for (int i = m, j = 0; i < m + n; i++) {
		arr3[i] = arr2[j++];
	}

	sort(arr3, arr3 + (m + n));

	for (int i = 0; i < m; i++) {
		arr1[i] = arr3[i];
	}

	for (int i = m, j = 0; i < m + n; i++) {
		arr2[j++] = arr3[i];
	}


	for (int i = 0; i < m; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
}


// Time Complexity : (m * n)
// Space Complexity : O(1)
void mergeTwoSortedArray2(int arr1[], int m, int arr2[], int n) {

	for (int i = 0; i < m; i++) {
		
		if (arr1[i] > arr2[0]) {
			swap(arr1[i], arr2[0]);
			int first = arr2[0];

			int k;

			for (k = 1; k < n && arr2[k] < first; k++) {
				arr2[k - 1] = arr2[k];
			}
			arr2[k - 1] = first;
		}
	}

	displayArray(arr1, m, arr2, n);
}

// Time Complexity : (m * n)
// Space Complexity : O(1)
int nextGap(int gap) {
	//It returns the ceil value of gap/2 or 0 if gap is 1.
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}
void mergeTwoSortedArray3(int arr1[], int m, int arr2[], int n) {
	int gap = m + n;
	int i, j;
	// gap = nextGap(gap);
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) { 
    	    //Comparing elements in the first array itself with difference in 
    	    //index equal to the value of gap. 
    		// cout << "GAP " << gap << endl;

    		for (i = 0; (i + gap) < m; i++) {
    		    //If element at ith index is greater than element at
    		    //(i+gap)th index, we swap them. 
    			if (arr1[i] > arr1[i + gap]) 
    				swap(arr1[i], arr1[i + gap]); 
    		}
    		// i--;
    		// cout << "I " << i << endl;
    		//Now comparing elements in both arrays with help of two pointers.
    		//The loop stops whenever any pointer exceeds the size of its array.
    		for (j = gap > m ? gap-m : 0 ; i < m && j < n; i++, j++){
    		    //If element in the first array is greater than element in
    		    //second array, we swap them. 
    			if (arr1[i] > arr2[j]) 
    				swap(arr1[i], arr2[j]); 
    		}
            
    		if (j < n) { 
    			//At last, comparing elements in the second array itself with 
                //difference in index equal to the value of gap.
    			for (j = 0; j + gap < n; j++) 
    			    //If element at jth index is greater than element at
    		        //(j + gap)th index, we swap them. 
    				if (arr2[j] > arr2[j + gap]) 
    					swap(arr2[j], arr2[j + gap]); 
    		} 
	

    	
	


	}	
		// displayArray(arr1, m, arr2, n);


}
    	

int main() {

	int arr1[] = {1, 4, 7, 8, 10};
	int arr2[] = {2, 3, 9};

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// mergeTwoSortedArray1(arr1, m, arr2, n);
	// mergeTwoSortedArray2(arr1, m, arr2, n);
	mergeTwoSortedArray3(arr1, m, arr2, n);
   displayArray(arr1, m, arr2, n);




	return 0;
}
