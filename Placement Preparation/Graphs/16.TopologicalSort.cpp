
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
            // l[y].push_back(x); // DAG 
        }

        void topologicalSort(){
            int V = this -> vertex;
            vector<int> inDegree(V, 0);
            queue<int> q;


            for(auto it : l){
                for(auto it2 : it.second){
                    inDegree[it2]++;
                }
            }


            for(auto it : inDegree){
                cout << it << " ";
            }
            cout << endl;

            for(int i = 0; i < V; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }

            while(q.size()){
                int node = q.front(); q.pop();
                cout << node << " ";

                for(int x : l[node]){
                    if(--inDegree[x] == 0){
                        q.push(x);
                     }
                }
            }
        }
        
};
int main() {

    Graph<int> g(5);
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 3);

    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort();
    

    return 0;
}


