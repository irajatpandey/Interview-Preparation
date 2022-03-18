
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
            // l[y].push_back(x);
        }


        bool isCyclic(int src, vector<bool> &visited, vector<bool> &recursiveStack){
            visited[src] = true;
            recursiveStack[src] = true;

            for(auto &it : l[src]){
                if(!visited[it] && isCyclic(it, visited, recursiveStack)){
                    return true;
                }
                else if(recursiveStack[it]) 
                    return true;
            }
            recursiveStack[src] = false;
            return false;
        }


};
int main() {

    Graph<int> g(7);

    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    vector<bool> visited(6, false);
    vector<bool> recursiveStack(6, false);

    bool flag = false;
    for(int i = 0; i < 6; i++){
        if(!visited[i]){
            if(g.isCyclic(i, visited, recursiveStack) == true){
                flag = true;
                cout << "True";
                break;
            }
        }
    }

    if(!flag){
        cout << "False";
    }

    

    return 0;
}


