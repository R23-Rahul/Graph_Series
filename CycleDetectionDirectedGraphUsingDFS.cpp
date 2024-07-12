#include<bits/stdc++.h>
using namespace std;
class Graph{
  public:
  unordered_map<int,list<int>>adjList;
  unordered_map<int,list<pair<int,int>>> WtadjList;

  void addEdge(int u, int v , bool direction){
  //if direction==0 => undirected graph
  //if direction==1=>directed Graph
    if(direction==1){
      adjList[u].push_back(v);
    }
    else{
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
 }

  void printAdjList(){
   for(auto i : adjList){
     cout<<i.first<<" -> { ";
     for(auto nbr : i.second){
      cout<<nbr<<", ";
     }
     cout<<" }"<<endl;
   }
  }

bool checkCycleInDirectedGraphDfs(int src, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited) {
    dfsVisited[src] = true;
    visited[src] = true;

    for (auto nbr : adjList[src]) {
        if (!visited[nbr]) {
            bool ans = checkCycleInDirectedGraphDfs(nbr, visited, dfsVisited, adjList);
            if (ans) {
                return true;
            }
        } else if (dfsVisited[nbr]) {
            return true;
        }
    }

    dfsVisited[src] = false; 
    return false;
}



};

int main() {
Graph g;
g.addEdge(1,2,1);
g.addEdge(1,3,1);
g.addEdge(3,4,1);
g.addEdge(2,3,1);
g.addEdge(2,6,1);
g.addEdge(4,5,1);
g.addEdge(3,5,1);

cout<<"adjList: "<<endl;
g.printAdjList();
unordered_map<int,bool>visited;
unordered_map<int, bool>dfsVisited;
cout<<"Cycle Check in Graph using DFS in directed Graph :"<<endl;
bool ans=false;
for(int i=1;i<=6;i++){
  if(!visited[i]){
     ans= g.checkCycleInDirectedGraphDfs(i,visited);
  }
}
if(ans){
  cout<<"Cycle Present"<<endl;
}
else{
  cout<<"No cycle"<<endl;
}
  return 0;
}
