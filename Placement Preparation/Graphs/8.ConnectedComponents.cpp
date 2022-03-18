#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
        T vertex;
        map<T, list<T>> l; 
    public:
        Graph(int n){
            this -> vertex = n;
        }
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void dfs(map<int, bool> &visited, int startingVertex, vector<int> &ans){
            if(!visited[startingVertex]){
                ans.push_back(startingVertex);
            }
            visited[startingVertex] = true;
           for(auto it : l[startingVertex]){ 
                if(!visited[it]){
                    visited[it] = true;
                    ans.push_back(it);
                    dfs(visited, it, ans);
                }
           }
        }

        vector<vector<int>> getAllConnectedComponents(){
           map<int, bool> visited;
            int startingVertex = -1;
            for(auto it : l){
                visited[it.first] = false;
                
            }

            vector<vector<int>> output;


           for(auto it : visited){
               cout << it.first << " ";
               if(it.second == false){
                    vector<int> ans;
                    
                    dfs(visited, it.first, ans);
                    output.push_back(ans);
               }
           }
           cout << endl;

           return output;
        }

};


int main() {

    int numberofVertices = 8;
    Graph<int> g(4);

    g.addEdge(0 , 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(4, 5);
    // g.addEdge(4, 6);
    // g.addEdge(5, 6); 





    // g.addEdge(0,1);
    // g.addEdge(0,3);
    // g.addEdge(1,2);
    // g.addEdge(2,3);


    // g.addEdge(0, 4);
    // g.addEdge(0, 5);
    // g.addEdge(4, 3);
    // g.addEdge(3, 2);
    // g.addEdge(2, 1);
    // g.addEdge(1, 3);
    // g.addEdge(5, 6);
    // g.addEdge(3, 6);
    // g.addEdge(6, 7);

    vector<vector<int>> ans = g.getAllConnectedComponents();
    for(auto it : ans){
        for(auto it2 : it){
           cout << it2 << " "; 
            
         }  
         cout << endl; 
    }
    



  
    // g.bfs();
    // g.dfs();

    


    return 0;
}
// 8 NO. OF VERTEX
// 9 NO. OF EDGES                                       /*      0
// 0 4                                                         / \
// 0 5                                                        /   \  
// 4 3                                                       4     5 
// 3 2                                                      /       \
// 2 1                                                     /         \   
// 1 3                                                    3-----------6  
// 5 6                                                   / \           \
// 3 6                                                  /   \           \
// 6 7                                                 2-----1           7  */



