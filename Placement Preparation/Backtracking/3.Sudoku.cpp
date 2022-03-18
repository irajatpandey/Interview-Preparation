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
bool isValid(vector<vector<int>> &board, int x, int y, int val){

	for(int j = 0; j < board.size(); j++){
		if(board[x][j] == val) 
			return false;
	}

	for(int i = 0; i < board.size(); i++){

		if(board[i][y] == val){
			return false;
		}
	}


	// check for sub-matrix


	int smallMatrix_i = (x / 3) * 3;
	int smallMatrix_j = (y / 3) * 3;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[smallMatrix_i + i][smallMatrix_j + j] == val){
					return false;
			}
		}
	}

	return true;
}

vector<vector<int>> ans;
void solve(vector<vector<int>> &board, int i, int j){
	// display(board);
	if(i == board.size()){
		// display(board);
		ans = board;
		return;
	}


	int next_i = 0;
	int next_j = 0;

	if(j == board.size() - 1){
		next_i = i + 1;
		next_j = 0;
	} 

	else{
		next_i = i;
		next_j = j + 1;
	}
	if(board[i][j] != 0){
		solve(board, next_i, next_j);
	}
	else{

		for(int possible_positions = 1; possible_positions <= 9; possible_positions++){
			if(isValid(board, i, j, possible_positions) == true){
				// cout << "true\n";
				board[i][j] = possible_positions;
				solve(board, next_i, next_j);
				board[i][j] = 0;
			}
		}
	}

}
vector<vector<int>> sudkouSolver(vector<vector<int>> &board){
	// cout << "he";

	vector<vector<int>> solution;
	solve(board, 0, 0);


	return ans;
}


	
int main(){

	vector<vector<int>> board =     {{3, 0, 6, 5, 0, 8, 4, 0, 0},
									{5, 2, 0, 0, 0, 0, 0, 0, 0},
									{0, 8, 7, 0, 0, 0, 0, 3, 1},
									{0, 0, 3, 0, 1, 0, 0, 8, 0},
									{9, 0, 0, 8, 6, 3, 0, 0, 5},
									{0, 5, 0, 0, 9, 0, 6, 0, 0},
									{1, 3, 0, 0, 0, 0, 2, 5, 0},
									{0, 0, 0, 0, 0, 0, 0, 7, 4},
									{0, 0, 5, 2, 0, 6, 3, 0, 0}};


	// display(board);

	vector<vector<int>> ans1;

	ans1 = sudkouSolver(board);


	for(auto it : ans){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}



	return 0;
}
