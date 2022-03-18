#include<bits/stdc++.h>
#define long long ll
using namespace std;

class Graph{
	private:
};


// DFS
void printGraph(vector<vector<bool>> adjacenyMatrix, int startingVertex, vector<bool> &visited){
	 int n = adjacenyMatrix.size();
	visited[startingVertex] = true;
	cout << startingVertex << " ";

	 for(int i = 0; i < n; i++){
	 	if(i == startingVertex){
	 		continue;
	 	}

	 	if(adjacenyMatrix[startingVertex][i] == true){
	 		if(visited[i]){
	 			continue;
	 		}
	 		printGraph(adjacenyMatrix, i, visited);
	 	}

	 }
}


// BFS

void printGraphBFS(vector<vector<bool>> adjacenyMatrix, int startingVertex){

	 queue<int> q;
	 q.push(startingVertex);
	 int n = adjacenyMatrix.size();
	 vector<bool> visited(n, false);

	 while(!q.empty()){
		 int currentVertx = q.front();

		 cout << currentVertx << " ";
		 q.pop();

		 for(int i = 0; i < n; i++){
			  if(i == startingVertex){
				 continue;
			 }

			 if(adjacenyMatrix[currentVertx][i] == true && !visited[i]){
				 q.push(i); 
				 visited[i] = true;
			 }
			
		 }

	 }

}

int main(){
	int vertices; cin >> vertices;
	int edges; cin >> edges;
	vector<vector<bool>> adjacenyMatrix;


	for(int i = 0; i < vertices; i++){
		vector<bool> edges(vertices, false);
		adjacenyMatrix.push_back(edges);

	}

	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			cout << adjacenyMatrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << edges << endl;


	for(int i = 0; i < edges; i++){
		int f, s;
		cin >> f >> s;
		adjacenyMatrix[f][s] = true;
		adjacenyMatrix[s][f] = true;

	}
	vector<bool> visited(vertices, false);
	int startingVertex = 0;
	cout << "DFS " << endl;
	printGraph(adjacenyMatrix, startingVertex, visited);
	cout << endl;
	cout << "BFS " << endl;

	printGraphBFS(adjacenyMatrix, startingVertex);


	return 0;
}
// Input 1:
// 4
// 3
// 0 2 
// 2 1
// 1 3

// Output : 0 4 3 1 2 6 5 7


// Input 2:
// 8
// 9
// 0 4 
// 0 5
// 4 3
// 3 2
// 2 1
// 1 3
// 5 6
// 3 6
// 6 7

// Output : 0 4 5 3 6 1 2 7