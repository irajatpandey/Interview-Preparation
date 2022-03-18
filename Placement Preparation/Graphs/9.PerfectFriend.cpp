// 1. You are given a number n (representing the number of students). Each student will have an id 
//      from 0 to n - 1.
// 2. You are given a number k (representing the number of clubs)
// 3. In the next k lines, two numbers are given separated by a space. The numbers are ids of 
//      students belonging to same club.
// 4. You have to find in how many ways can we select a pair of students such that both students are 
//      from different clubs.

// Sample Input
// 7
// 5
// 0 1
// 2 3
// 4 5
// 5 6
// 4 6

// Sample Output

// 16

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
        void takeAllComponents(int sv, map<T, bool> &visited, vector<vector<int>> &ans){
             visited[sv] = true;
             vector<int> v;
             v.push_back(sv);   
             for(auto it : l[sv]){
                 visited[it] = true;
                 v.push_back(it);
             }

             ans.push_back(v);
        }
        vector<vector<int>> getAllComponents(){
            map<T, bool> visited;
            vector<vector<int>> ans;

            for(auto it : l){
                visited[it.first] = false;
            } 

            for(auto it : visited){
                if(!visited[it.first]){
                    takeAllComponents(it.first, visited, ans);
                }
            }

            return ans;


        }

       

};
int main() {

    Graph<int> g(7);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 6);
    
    vector<vector<int> > ans;
    ans = g.getAllComponents();
    int cnt = 0;
   for(int i = 0; i < ans.size(); i++){
       for(int j = i + 1; j < ans.size(); j++){
           cnt += ans[i].size() * ans[j].size();
       
       }
   }
    cout << cnt << endl;
    return 0;
}


