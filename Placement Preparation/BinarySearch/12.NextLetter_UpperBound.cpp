#include<bits/stdc++.h>
using namespace std;
int main(){


    char res;
    vector<char> a = {'a', 'c', 'f', 'h'};
    int n = a.size();
    int start = 0, end = n - 1;

    char ele = 'f';
    while (start <= end){
      
        int mid = (start + end) / 2;
       
        if (a[mid] > ele){
            end = mid - 1;
        }
        else{
            // res = a[mid];
            start = mid + 1;
        }
    }
    cout << a[start % n];
}