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

        void display(){
           
           for(auto it : l){
               cout << it.first << ": ";
               for(auto listItem : it.second){
                   cout << listItem << " ";
               }
               cout << endl;
           }
        }

        void dfs(unordered_map<T,bool> &visited, int startingVertex){
             
             for(auto it : l[startingVertex]){
                
                    if(!visited[it]){
                        visited[it] = true;
                        dfs(visited,it);
                    }
                
             }

        }

        bool isConnected(){
            unordered_map<T, bool> visited;
            int startingVertex = -1;


            for(auto it : l){
                if(startingVertex == -1){
                    startingVertex = it.first;
                }
                visited[it.first] = false;
            }
         
            
            cout << startingVertex << endl;
            dfs(visited, startingVertex);        

            for(auto it : visited){
                cout << it.first << " " << it.second << endl;
                if(it.second == false){
                return false;
                }
            }
            return true;

        }
  

};


int main() {

    int numberofVertices = 8;
    Graph<int> g(4);

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

  
    // g.bfs();
    // g.dfs();

     cout << g.isConnected();
    


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



