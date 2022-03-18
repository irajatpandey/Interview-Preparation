#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
        T V;
        map<T, list<pair<T,T>>> list;
    public:
        Graph(T V){
            this -> V = V;
        }

        void addEdge(T x, T y, T w){
            list[x].push_back({y, w});
            list[y].push_back({x, w});
        }

        int prism_MST(){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            vector<bool> visited(V, false);
            int ans = 0;

            // {weight, node_value}
                pq.push({0,0});
                while(pq.size() > 0){
                    // Pick out the edge with the min weight

                    auto best = pq.top(); 
                    pq.pop(); 

                    int weight = best.first;
                    int to = best.second;

                    if(visited[to] == true){
                        continue;
                    }

                    visited[to] = true;
                    ans += weight;
                    for(auto it : list[to]){
                    // cout << xyz.first << " " << xyz.second << endl;
                        if(visited[it.first] == false){
                            pq.push({it.second, it.first});
                        }
                    }
                    

                }
            
            cout << endl << endl;

            // for(auto it : list){
            //     cout << it.first << " ";
            // }
            return ans;
        }

};
int main() {

         // So, overall time complexity
        // = O(E + V) x O(logV)
       // = O((E + V)logV)
      // = O(ElogV)


    int n, m; cin >> n >> m;
    Graph<int> g(n);

    for(int i = 1; i <= m; i++){
        int v1, v2, wt; cin >> v1 >> v2 >> wt;
        g.addEdge(v1-1, v2-1, wt);
    }    

    cout << g.prism_MST();

    return 0;
}

// 7 9
// 1 6 10
// 1 2 28
// 2 7 14
// 2 3 16
// 3 4 12
// 4 7 18
// 5 6 25
// 5 7 24
// 5 4 22

// output : 99