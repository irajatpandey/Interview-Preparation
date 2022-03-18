
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

        int nodeLevel(int X){
            vector<bool> visited(vertex, false);
            vector<int> level(vertex);
            queue<int> q;


            q.push(0); // source always starts with 0
            visited[0] = true;

            while(!q.empty()){
                int x = q.front(); q.pop();
                if(X == x){
                    return level[x];
                }

                for(auto it : l[x]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = false;
                        level[it] = level[x] + 1;
                    }
                }


            }
            return -1;
        }
};
int main() {

    Graph<int> g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    int X = 4;

    cout << g.nodeLevel(X); 
    // expected output 2

    return 0;
}



