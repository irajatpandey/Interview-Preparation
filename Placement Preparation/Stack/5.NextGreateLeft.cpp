#include <bits/stdc++.h>
using namespace std;


vector<int> nearestGreaterToLeft1(int *arr, int n) {

    vector<int> ans;
    bool flag = true;
    for (int i = n - 1; i >= 0; i--) {
        flag = true;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                ans.push_back(arr[j]);
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.push_back(-1);
        }


    }
    return ans;
}

vector<int> nearestGreaterToLeft2(int *arr, int n) {
    vector<int> ans;
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            ans.push_back(-1);
        }

        if (s.size() > 0 and s.top() > arr[i]) {
            ans.push_back(s.top());
        }

        else if (s.size() > 0 and s.top() <= arr[i]) {
            while (s.size() > 0 and s.top() <= arr[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                ans.push_back(-1);
            }

            else {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    return ans;
}


int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> output = nearestGreaterToLeft2(arr, n);

    reverse(output.begin(), output.end());
    cout << "Output vector : ";
    for (auto it : output) cout << it << " ";
    return 0;



}