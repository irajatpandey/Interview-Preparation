#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    map<int, list<pair<int, int> > > l;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int u, int v, int wt, bool undirected = true)
    {
        l[u].push_back({ v, wt });
        if (undirected) {
            l[v].push_back({ u, wt });
        }
    }

    int dijkastra(int source, int destination)
    {
        vector<int> distance(V, INT_MAX);
        set<pair<int, int> > s;  // this pair will hold {distanceTillNow, node(Vertex)}
        s.insert({ 0, source }); // 
        distance[source] = 0;

        while (!s.empty()) {
            auto it = s.begin();
            int distanceTillNow = it->first;  // DistanceTillNow from Source
            int node = it->second;  // current Vertex
            s.erase(it);


            // Iterate over all the adjacent node and perform the relaxation and update their distanceTillNow
            // Intital DistanceTill now will be INT_MAX
            for (auto nbrPair : l[node]) {

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

        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " Distane " << distance[i] << endl;
        }

        return distance[destination]; // this is the distance/cost in order to reach from soource to destination
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkastra(0, 4) << endl;

    return 0;
}