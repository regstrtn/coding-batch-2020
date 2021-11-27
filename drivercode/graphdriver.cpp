#include<iostream>
 #include<stdio.h>
#include<fstream>
#include<vector> 
#include<queue>

using namespace std; 

class Graph {
  public:
  bool bi = false;
  int N;
  
  vector<vector<int>> adj; // adjacency matrix. 
  
  Graph(int nodes,bool dir) {
    N = nodes;
    adj.resize(N, vector<int> ());
    bi = dir;
  }
  
  // Directed graph. Make sure nodes are zero indexed. 
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    if(bi)
      adj[v].push_back(u);
  }
  
  // Write BFS Code. 
  void bfs(int start) {
    queue<int> q; 
    q.push(start);
    vector<bool> visited(N,false);
    while(!q.empty()){
      
      int v = q.front();
      visited[v] = true;
      q.pop();
      for(auto nbr : adj[v]){
        if(visited[nbr] == true)
            continue;
          cout<<v<<" "<<nbr<<endl;
        q.push(nbr);
      }

    }

    return;
  }

  // Print shortest path from start node to end node.  
  // void printBfsPath(int start, int end) {
  // }
  
  // use bfs.
  // vector<int> getShortestDistanceToAllNodes(int start) {
  //   return {1};
  // }
  
  // Why dfsForest? Because the graph may not be connected. 
  // void dfsForest(int start) {
  // }
  
  // This is the actual method that will be called recursively for dfs exploration. 
  // void dfsTree(int start) {
  // }
  
  // Solve using dfs (or any other method you know). 
  // bool isCyclic() {
  // }
  
  // Return vector with all nodes in topological order. If not possible, return empty vector. 
  // vector<int> topologicalSort() {
  // }
  
  // For implementation, this is the best shortest path algorithm to implement. Djikstra is difficult to implement. 
  // For an unweighted graph, compare the output of this with the BFS algorithm. 
  // Return shortest path to all nodes. 
  // vector<int> bellmanFord(int start) {
  // }
  
};

int main() {
  
  // Assignment 1: 
  // Create a text file that contains : (1) Number of nodes, and (2) List of edges. 
  // Read this edge list from the text file. 
  // Complete the methods above and run all methods on the graph you built in your text file. 
  // Try with disconnected graph, cyclic graph etc. 
  
  #ifndef checkmate
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n; cin>>n;
  
  // cout<<n<<endl;
  Graph adj = Graph(n,false);
  cin>>n;
  for(int i=0;i<n;i++){
    int u,v; cin>>u>>v;
    adj.addEdge(u,v);
  }

  adj.bfs(0);

  // Read text files using ifstream. You can refer learncpp.com for this.
  
  // Assignment 2: 
  // Now add weights to your edges and read the weighted graph in your adjacency matrix. 
  // Run bellman ford algorithm to print shortest paths. 
}
