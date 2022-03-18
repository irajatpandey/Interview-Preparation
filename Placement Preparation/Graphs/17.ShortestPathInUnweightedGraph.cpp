
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
        T vertex;
        map<T, list<T>> l; 

    public:
        Graph(T vertex){
            this -> vertex = vertex;
        }
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        vector<int> shortestPathInUnWeightedGraph(){
            vector<int> ans;
            vector<int> distances(vertex, INT_MAX);
            distances[0] = 0;
            vector<bool> visited(vertex, false);

            queue<int> q;


            q.push(0);
            while(q.size() > 0){
                int node = q.front(); q.pop();

                for(auto it : l[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                        distances[it] = distances[node] + 1;
                    }
                 }
             }
            

            return distances;
        }
};
int main() {

    Graph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    vector<int> output = g.shortestPathInUnWeightedGraph();

    for(auto it : output){
        cout << it << " ";
    }

    

    return 0;
}


