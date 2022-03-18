
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

       void printAllPath(int source, unordered_set<int> &visited, string ans, int originalSource){
            
           if(l.size() - 1 == visited.size()){
               cout << ans;
               bool flag = false;


               for(auto it : l[source]){
                   if(it == originalSource){
                       flag = true;
                       break;
                   }
               }

               if(flag){
                   cout << "*" << endl;
               }
               else{
                   cout << "." << endl;
               }
               return;
           }
            visited.insert(source);
            for(auto vertex : l[source]){
                if(visited.find(vertex) == visited.end()){
                    
                    printAllPath(vertex, visited, (ans + to_string(vertex)), originalSource);
                }
            } 
            auto it = visited.find(source);
            visited.erase(it);
           
       }


};
int main() {

    Graph<int> g(7);
    int source = 0;
    int originalSource = 0;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 6);
    g.addEdge(2, 5);
    int V = 7;
    unordered_set<int> visited;
  
   
    string ans = to_string(source);
    g.printAllPath(source, visited, ans, originalSource);


    

    return 0;
}


