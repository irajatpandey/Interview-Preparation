
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


        bool isCyclic(int src, vector<bool> &visited){
            queue<int> q;

            q.push(src);
            // visited[src] = true;

            while(q.size()){
                int temp = q.front(); q.pop();
                
                if(visited[temp] == true){
                  
                    return true;
                }
                
                visited[temp] = true;
              
                    for(auto it : l[temp]){
                        if(!visited[it]){
                            q.push(it);
                        }
                    }
                
            }

            return false;
        }
};
int main() {

    Graph<int> g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    vector<bool> visited(7, false);
    bool flag = false;
    for(int i = 0; i < 7; i++){
        if(!visited[i]){
            if(g.isCyclic(i, visited) == true){
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


