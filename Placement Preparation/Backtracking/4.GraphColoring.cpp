#include<bits/stdc++.h>
#define long long ll
using namespace std;


// Time Complexity : O(n ^ m) // no of vertices, m no of colors
class Graph{

	int V;
	map<int, list<int>> l;
public:

	Graph(int V){
		this -> V = V;
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool isSafe(int node, vector<int> &colors, int i){
		for(auto it : l[node]){
			if(colors[it] == i){
				return false;
			}
		}

		return true;
	}
	bool solve(vector<int> &colors, int m, int startingVertex){
		if(startingVertex == V){
			return true;
		}


		for(int i = 1; i <= m; i++){
			if(isSafe(startingVertex, colors, i)){
				colors[startingVertex] = i;
				if(solve(colors, m, startingVertex + 1)) return true;
				colors[startingVertex] = 0;
			}
		}

	}
	void bfs(int startingVertex){
		queue<int> q;
		vector<bool> visited(V, false);
		q.push(startingVertex);
		while(q.size()>0){
			int temp = q.front(); q.pop();
			cout << temp << " ";
			visited[temp] = true;
			for(auto it : l[temp]){
				if(!visited[it]){
					q.push(it);
					visited[it] = true;
				}
				
			}

		}
	}


	bool graphColoring(int m){
		vector<int> colors(V, 0);
		 if(solve(colors, m, 0)) return true; 
	}
};
	
int main(){

	Graph g(8);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 2);

    g.bfs(0);
    cout << endl;

    g.graphColoring(3) == 1 ? cout << "True" : cout << "false";

	return 0;
}
