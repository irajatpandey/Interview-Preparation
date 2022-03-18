#include<bits/stdc++.h>
#define long long ll
using namespace std;



bool isValidPlace(vector<vector<int>> &chessBoard, int row, int col){
	// Check for vertical 

	for(int i = row - 1, j = col; i >= 0; i--){
		if(chessBoard[i][j] == 1){
			return false;
		}
	}

	// Check for left diagonal

	for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
		if(chessBoard[i][j] == 1){
			return false;
		}
	}


	// check for right diagonal

	for(int i = row - 1, j = col + 1; i >= 0 && j < chessBoard.size(); i--, j++){
		if(chessBoard[i][j] == 1){
			return false;
		}
	}
	return true;
}
void solveNQueen(vector<vector<int>> &chessBoard, int n, int row, string qsf){
	if(n == row){
		cout << qsf << endl;
		return;
	}

	 for(int col = 0; col < n; col++){

	 	if(isValidPlace(chessBoard, row, col) == true){
	 		chessBoard[row][col] = 1;
	 	
	 	
		 	solveNQueen(chessBoard, n, row + 1, qsf + to_string(row) + "-" + to_string(col) + " ");
		 	chessBoard[row][col] = 0;
	 	}
	 }
}
 
void nQueen(int n){
	vector<vector<int>> chessBoard(n,vector<int> (n, 0));

	int row = 0;
	int col = n;
	solveNQueen(chessBoard, n, row, "");
}
	
int main(){

	int n = 1;

	nQueen(n);
	return 0;
}
