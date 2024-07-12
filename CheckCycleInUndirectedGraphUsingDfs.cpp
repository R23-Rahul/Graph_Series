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


bool checkCycleInUndirectedGraphDfs(int src,unordered_map<int,bool>&visited,  int &parent){
   visited[src]=true;
   for(auto i : adjList[src]){
    if(i==parent){
      continue;
    }
    else if(!visited[i]){
     bool ans= checkCycleInUndirectedGraphDfs(i,visited,src);
     if(ans){
      return true;
     }  
    }
    else if(visited[i]){
      return true;
    }
  
   }
   return false;
}

};

int main() {
Graph g;
g.addEdge(1,2,0);
g.addEdge(1,3,0);
g.addEdge(3,4,0);
g.addEdge(2,3,0);
g.addEdge(2,6,0);
g.addEdge(4,5,0);
g.addEdge(3,5,0);

cout<<"adjList: "<<endl;
g.printUnWeightedAdjList();
unordered_map<int,bool>visited;

cout<<"Cycle Check in Graph using DFS in undirected Graph :"<<endl;
bool ans=false;
  int parent=-1;
for(int i=1;i<=6;i++){
  if(!visited[i]){
     ans= g.checkCycleInUndirectedGraphDfs(i,visited,parent);
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
//=================OUTPUT============
// adjList: 
// 5 -> { 4, 3,  }
// 6 -> { 2,  }
// 4 -> { 3, 5,  }
// 3 -> { 1, 4, 2, 5,  }
// 1 -> { 2, 3,  }
// 2 -> { 1, 3, 6,  }
// DFS traversal of Graph:
// Cycle Present
