#include<bits/stdc++.h>
#define long long ll
using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(1)
vector<int> majoritElement_mooresVotingAlgo(vector<int> &arr){
	int c1 = 0, c2 = 0, val1 = -1, val2 = -1;
        for(int it : arr){
            if(it == val1) c1++;
            else if(it == val2) c2++;
            
            else if(c1 == 0){
                val1 = it;
                c1 = 1;
            }
            else if(c2 == 0){
                val2 = it;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        int cnt1 = 0, cnt2 = 0;
        for(int it : arr){
            if(it == val1) cnt1++;
            else if(it == val2) cnt2++;
        }
        
        
        vector<int> ans;
        if(cnt1 > arr.size()/3) ans.push_back(val1);
        if(cnt2 > arr.size()/3) ans.push_back(val2);
        return ans;
	

}




	
int main(){

	vector<int> arr = {10, 10, 20, 30, 10, 10};
	
	vector<int> ans =  majoritElement_mooresVotingAlgo(arr);
	for(auto it : ans){
		cout << it << " ";
	}



	return 0;
}
