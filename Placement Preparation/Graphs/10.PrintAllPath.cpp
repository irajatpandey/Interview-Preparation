
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

       void printAllPath(int source, int destination, vector<bool> &visited, string ans){
            if(source == destination){
                 cout << ans << endl;
                 return;
            }
            visited[source] = true;
            for(auto vertex : l[source]){
                if(visited[vertex] == false){
                    printAllPath(vertex, destination, visited, ans + to_string(vertex));
                }
            } 
            visited[source] = false;

       }    

};
int main() {

    Graph<int> g(7);
    int source = 0;
    int destination = 6;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 6);
    int V = 7;
    vector<bool> visited(V, false);
    string ans = to_string(source);
    g.printAllPath(source, destination, visited, ans);


    return 0;
}


