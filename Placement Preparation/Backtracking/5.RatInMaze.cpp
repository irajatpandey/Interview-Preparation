#include<bits/stdc++.h>
#define long long ll
using namespace std;
void display(vector<vector<int>> board){
	for(auto it : board){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void helper(vector<vector<int>> &m, int i, int j, int n, vector<string>&res, string path) {
    if(i < 0 || i >= n || j < 0 || j >= n || m[i][j] != 1){
    	return;
    }


    if(i == n - 1 && j == n - 1){
        res.push_back(path);
        return ;
    }
    // For GFG m[i][j] = -1;
    m[i][j] = 0;
    display(m);
    cout << path << endl;
    helper(m, i + 1, j, n, res, path + 'D');
    helper(m, i - 1, j, n, res, path + 'U');
    helper(m, i ,j + 1, n, res, path + 'R');
    helper(m, i ,j - 1, n, res, path + 'L');

    m[i][j] = 1;
}
vector<string> printPath(vector<vector<int>> &m, int n) {
    vector<string> res;
    string s = "";
    helper(m, 0, 0, n, res, s);
    // sort(res.begin(),res.end());
    return res;     
}
	
int main(){

	vector<vector<int>> maze =  {{1, 0, 0, 0},
                                 {1, 1, 0, 1}, 
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1}};

    vector<string> ans = printPath(maze, 4);
    for(auto it : ans){
    	cout << it << endl;
    }


	return 0;
}
