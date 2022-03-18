#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> roads,int n)
{
     int source = 1;   
     vector<vector<pair<int,int>>> adj(n+1);
 
     for(auto edge: roads){
 
         int v1 = edge[0];
         int v2 = edge[1];
         int wt = edge[2];
 
         adj[v1].push_back({v2,wt});
         adj[v2].push_back({v1,wt});
 
     }


     vector<int> distance(n + 1, INT_MAX);
        set<pair<int, int> > s;  // this pair will hold {distanceTillNow, node(Vertex)}
        s.insert({ 0, source }); // 
        distance[source] = 0;
        vector<int> ans;
        ans.push_back(source);

        while (!s.empty()) {
            auto it = s.begin();
            int distanceTillNow = it->first;  // DistanceTillNow from Source
            int node = it->second;  // current Vertex
            
            s.erase(it);


            // Iterate over all the adjacent node and perform the relaxation and update their distanceTillNow
            // Intital DistanceTill now will be INT_MAX
            for (auto nbrPair : adj[node]) {

                int nbr = nbrPair.first;
                int currentEdge = nbrPair.second;

                if (distanceTillNow + currentEdge < distance[nbr]) {
                    auto f = s.find({ distance[nbr], nbr });
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    distance[nbr] = distanceTillNow + currentEdge;
                    s.insert({ distance[nbr], nbr });
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << "Node " << i << " Distane " << distance[i] << endl;
        }

 
  return ans;
}
 
 
int main(){
	
	vector<vector<int>> v = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {1, 5, 1}};
	int n = 5;
	
	vector<int> ans = shortestPath(v, n);
	for(auto it : ans) cout << it << " ";
	
}