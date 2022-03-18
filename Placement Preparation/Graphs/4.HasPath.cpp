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
        void bfsHelper(T startingVertex,  map<T, bool> &visited){
           cout << "BFS: ";
           queue<T> q;
           q.push(startingVertex);
          
           

           visited[startingVertex] = true;
          

           while(q.size() > 0){
               T node = q.front();
               q.pop();
               cout << node << " ";

               for(int neighbor : l[node]){
                
                if(visited[neighbor] == false){
                   q.push(neighbor);
                   visited[neighbor] = true;
                 }
               }  
              

           }
           cout << endl; 

        }

        void bfs(){
            map<T, bool> visited;

            for(auto it : l){
                for(auto vertex : it.second){
                    if(!visited[it.first]){
                        visited[it.first] = true;
                        bfsHelper(it.first, visited);
                  
                    }

                }
            }
        }
      
        void dfsHelper(T startingVertex, map<T, bool> &visited){

            visited[startingVertex] = true;
            cout << startingVertex << " ";

            // GO to all the neighbors of the startingVertex which are not visited
            for(auto it : l[startingVertex]){
                if(!visited[it]){
                    dfsHelper(it, visited);
                }
            }

        }
  

        
        void dfs(){
            map<int, bool> visited;

            for(auto it : l){
                for(auto vertex : it.second){
                    if(!visited[it.first]){
                    dfsHelper(it.first, visited);
                    cout << endl;
                    }
                }
            }

        }

        bool hasPathDFS(T vertex, T end){
            for(auto it : l[vertex]){
                if(it == end){
                    return true;
                }
            }
            return false;
        }
        bool hasPath(T start, T end){
            for(auto it : l){
                if(it.first == start){
                   return hasPathDFS(it.first, end);
                }
            }
        }
       
       
};


int main() {

    int numberofVertices = 8;
    Graph<int> g(8);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(4, 3);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.addEdge(5, 6);
    g.addEdge(3, 6);
    g.addEdge(6, 7);

  
    g.bfs();
    g.dfs();
    

    cout << g.hasPath(3, 12);


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



