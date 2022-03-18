    #include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerLeft(int *arr, int n){
        vector<int> left;
        int  psedoIndex = -1;
        stack<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        if(s.size() == 0){
            left.push_back(psedoIndex);
        }
        else if(s.size() > 0 && s.top().first < arr[i]){
            left.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= arr[i]){
            
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }

            if(s.size() == 0){
                left.push_back(psedoIndex);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    // reverse(left.begin(), left.end());
    return left;
}

vector<int> nextSmallerRight(int *arr, int n){
        vector<int> right;
        int psedoIndex = n;
        stack<pair<int, int>> s;

    for(int i = n - 1; i >= 0; i--){
        if(s.size() == 0){
            right.push_back(psedoIndex);
        }
        if(s.size() > 0 && s.top().first < arr[i]){
            right.push_back(s.top().second);
        }
        if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }

            if(s.size() == 0){
                right.push_back(psedoIndex);
            }
            else{
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    return right;

}

int maximumArea(int *arr, int n){
    vector<int> left = nextSmallerLeft(arr, n);
    vector<int> right = nextSmallerRight(arr, n);
    vector<int> width(n);
    vector<int> ans(n);
    cout << "NGL " << endl;
    for(auto it : left) cout << it << " ";
    cout << endl;
    for(int i = 0; i < n; i++){
        width[i] = right[i] - left[i] - 1;
    }

   

    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        ans[i] = arr[i] * width[i];
        max = max < ans[i] ? ans[i] : max;
    }

   return max;
}
int main() {

    vector<int> width;
     int arr[] = {6, 2, 5, 4, 5, 1, 6};
     int n = sizeof(arr)/sizeof(arr[0]);

     int ans = maximumArea(arr, n);
     cout <<"Largest Area of Histogram " << ans << endl;

    return 0;
}