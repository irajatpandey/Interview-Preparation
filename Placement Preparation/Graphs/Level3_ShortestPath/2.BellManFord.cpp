#include<bits/stdc++.h>
#define long long ll
using namespace std;


class Triplet{
	public:
		int u;
		int v;
		int wt;

	Triplet(int u, int v, int wt){
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};	
class Graph{
	int V;
	vector<Triplet> edges;
	public:
		Graph(int V){
			this->V = V;
		}
	void addEdge(int u, int v, int wt){
		edges.push_back(Triplet(u, v, wt));
	}

	// Time Complexity : O(V * E)
	// V Number of Vertex
	// E Number of Edges

	// When Graph is fully connected then
	// numberOfEdges = n*(n - 1)/2;
	// let V = n - 1, and E = n *(n - 1)/2;
	// worstcase: O(n - 1 * (n *(n - 1)/2) = O(n^3)

	vector<int> bellManFord(int src){
		int numberOfEdges = edges.size();
		cout << "Number of edges: " << numberOfEdges << endl;
		vector<int> distance(numberOfEdges + 1, INT_MAX); // for the vertex from 1 to V
		distance[src] = 0;
		
		for(int i = 0; i < numberOfEdges - 1; i++){
			for(auto edge : edges){
				int u = edge.u;
				int v = edge.v;
				int wt = edge.wt;

				// cout << u << " " << v << " " << wt << endl;


				if(distance[u] != INT_MAX and distance[u] + wt < distance[v]){
					distance[v] = distance[u] + wt;
				}
			}
		}

		for(auto edge : edges){
				int u = edge.u;
				int v = edge.v;
				int wt = edge.wt;

				if(distance[u] != INT_MAX and distance[u] + wt < distance[v]){
					cout << "Graph Contains Negative Edge Cycle!!" << endl;
					exit(0);
				}
			}

		return distance;
	}

	void display(){
		for(auto it : edges){
			cout << it.u << " " << it.v << " " << it.wt << endl;
		}
	}


};
	
int main(){

	Graph g(7);

	g.addEdge(1, 2, 6);
	g.addEdge(1, 3, 5);
	g.addEdge(1, 4, 5);
	g.addEdge(2, 5, -1);
	g.addEdge(3, 2, -2);
	g.addEdge(3, 5, 1);
	g.addEdge(4, 3, -2);
	g.addEdge(4, 6, -1);
	g.addEdge(5, 7, 3);
	g.addEdge(6, 7, 3);


	// g.display();
	vector<int> ans = g.bellManFord(1);
	for(int i = 1; i <= 7; i++){
		cout << "Node: " << i << " " << ans[i] << endl;
	}
	return 0;
}
// output
// Node: 1 0
// Node: 2 1
// Node: 3 3
// Node: 4 5
// Node: 5 0
// Node: 6 4
// Node: 7 3