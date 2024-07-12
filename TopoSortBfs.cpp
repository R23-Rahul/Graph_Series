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
  void printUnWeightedAdjList(){
   for(auto i : adjList){
     cout<<i.first<<" -> { ";
     for(auto nbr : i.second){
      cout<<nbr<<", ";
     }
     cout<<" }"<<endl;
   }
  }
  

void BfsTopoSort( unordered_map<int,bool>&visited,int n){
 queue<int>q;
 unordered_map<int,int>indegree;
 for(auto i : adjList){
  int src=i.first;
  for(auto nbr : i.second){
    indegree[nbr]++;
  }
 }
 for(int i=1;i<n;i++){
  if(indegree[i]==0){
    q.push(i);
  }
 }

while(!q.empty()){
  int frontNode=q.front();
  q.pop();
  cout<<frontNode<<" ";
  for(auto nbr : adjList[frontNode]){
    indegree[nbr]--;
    if(indegree[nbr]==0){
      q.push(nbr);
    }
  }
}

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
g.printUnWeightedAdjList();
unordered_map<int,bool>visited;

 cout<<"Topological Sort using BFS :"<<endl;

    g.BfsTopoSort(visited,6);

  return 0;
}

//===============================OUTPUT=======================
// adjList: 
// 4 -> { 5,  }
// 2 -> { 3, 6,  }
// 1 -> { 2, 3,  }
// 3 -> { 4, 5,  }
// Topological Sort using BFS :
// 1 2 3 6 4 5 
