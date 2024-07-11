#include<bits/stdc++.h>
using namespace std;
class Graph{
  public:
  unordered_map<int,list<int>>adjList;

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
  void printAdjList(){
   for(auto i : adjList){
     cout<<i.first<<" -> { ";
     for(auto nbr : i.second){
      cout<<nbr<<", ";
     }
     cout<<" }"<<endl;
   }
  }
//BFS Traversal 
void BfsTraversal(int src,unordered_map<int,bool>&visited){
  //create a queue
  queue<int>q;
  
  q.push(src);  // push starting Node
  visited[src]=true;  // mark visited true for the starting vertex
  
  while(!q.empty()){
    int frontNode=q.front(); // fetch first element of queue
    q.pop(); //pop out that element
    cout<<frontNode<<" "; // print that element
    for(auto i:adjList[frontNode]){   // now traverse throught the adj list of that node
      if(!visited[i]){   // check that is nbr node of frontNode is already visited or not -> if not then
        q.push(i); // push that element in queue
        visited[i]=true; // mark that visited 
      }
    }
  }
};

int main() {
Graph g;
g.addEdge(1,2,0);
g.addEdge(1,3,0);
g.addEdge(3,4,0);
g.addEdge(2,6,0);
g.addEdge(4,5,0);
g.addEdge(3,5,0);
cout<<"adjList:"<<endl;
  g.printAdjList();
unordered_map<int,bool>visited;
  cout<<"BFS traversal of Graph:"<<endl;
for(int i=1;i<=6;i++){
  if(!visited[i]){  // here the loop used bcz we want to ensure that code will work in disconnect component case also
     g.BfsTraversal(i,visited);
  }
}

  return 0;
}


// =============output===========
// adjList: 
// 5 -> { 4, 3,  }
// 6 -> { 2,  }
// 4 -> { 3, 5,  }
// 3 -> { 1, 4, 5,  }
// 1 -> { 2, 3,  }
// 2 -> { 1, 6,  }
// BFS traversal of Graph:
// 1 2 3 6 4 5 
