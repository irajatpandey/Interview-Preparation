#include<bits/stdc++.h>
#define long long ll
using namespace std;

void displyChessBoard(vector<vector<int>> &chess){
	for(auto it : chess){
		for(auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void knight_tour(vector<vector<int>> &chess, int row, int col, int move){
	if(row < 0 || col < 0 || row >= chess.size() || col >= chess.size() || chess[row][col] > 0) {
		return;
	}

	else if(move == (chess.size() * chess.size())){
		chess[row][col] = move;
		displyChessBoard(chess);
		chess[row][col] = 0;
		return;
	}

	chess[row][col] = move;
	knight_tour(chess, row - 2, col + 1, move + 1);
	knight_tour(chess, row - 1, col + 2, move + 1);
	knight_tour(chess, row + 1, col + 2, move + 1);
	knight_tour(chess, row + 2, col + 1, move + 1);
	knight_tour(chess, row + 2, col - 1, move + 1);
	knight_tour(chess, row + 1, col - 2, move + 1);
	knight_tour(chess, row - 1, col - 2, move + 1);
	knight_tour(chess, row - 2, col - 1, move + 1);

	chess[row][col] = 0;



}
	
int main(){
	int n = 5;

	vector<vector<int>> chess(n, vector<int>(n, 0));
	knight_tour(chess, 2, 4, 1);
	return 0;
}
