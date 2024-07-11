#include <iostream>
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
  void weightedEdgeAdd(int u,int v, int wt, bool direction){
    if(direction==1){
      WtadjList[u].push_back({v,wt});
    }
    else{
      WtadjList[u].push_back({v,wt});
      WtadjList[v].push_back({u,wt});
    }

  }

  void printUnWeightedAdjList(){
   for(auto i : adjList){
     cout<<i.first<<" -> { ";
     for(auto nbr : i.second){
      cout<<nbr<<", ";
     }
     cout<<endl;
   }
  }
  void printWeightedAdjList(){
   for(auto i: WtadjList){
    cout<<i.first<<"->{ ";
    for(auto nbr:i.second){
          cout<<"("<<nbr.first<<","<<nbr.second<<"), ";
    }
    cout<<" }"<<endl;
   }
  }


};

int main() {
Graph g;
g.weightedEdgeAdd(1,2,5,0);
g.weightedEdgeAdd(2,3,8,0);
g.weightedEdgeAdd(2,4,10,0);
g.printWeightedAdjList();
  return 0;
}
