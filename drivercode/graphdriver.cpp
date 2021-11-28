#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector> 
#include<queue>
#include<algorithm>
#include <climits>

using namespace std; 

class Graph {
  public:
  bool bi = false;
  int N;
  int E;
  
  vector<vector<int>> adj; // adjacency matrix. 
  vector<vector<int>> edges; // weighted adjacency matrix
  
  Graph(int nodes,bool dir,int m) {
    N = nodes;
    adj.resize(N, vector<int> ());
    bi = dir;
    E = m;
  }
  
  // Directed graph. Make sure nodes are zero indexed. 
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    if(bi)
      adj[v].push_back(u);
  }

  // added wieghted edge
  void addEdgeW(int u, int v, int w){
    edges.push_back({u,v,w});
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
  void printBfsPath(int start, int end) {
    vector<int> parent (N,-1);
    parent[start] = start;
    vector<bool> vis(N,false);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      vis[u] = true;
      for(int v:adj[u]){
        if(!vis[v]){
          parent[v] = u;
          q.push(v);
        }

      }
    }

    while(parent[end] != end){
      cout<<end<<" -> ";
      end = parent[end];
    }
    cout<<end<<endl;
    return;
  }
  
  // use bfs.
  vector<int> getShortestDistanceToAllNodes(int start) {
    vector<int> dis(N,-1);
    dis[start] = 0;
    queue<int> q;
    q.push(start);
    vector<bool> vis(N);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      vis[u] = true;
      for(int nbr: adj[u]){
        if(vis[nbr]) continue;
        if(dis[nbr]==-1) dis[nbr] = dis[u]+1;
        q.push(nbr);
      }
    }
  return dis;

  }
  
  // Why dfsForest? Because the graph may not be connected. 
  void dfsForest(int start) {
    vector<bool> vis(N);
    for(int i=0;i<N;i++){
      if(!vis[i]){

        dfsTree(i,vis);
        cout<<endl;
      }
    }
  }
  
  // This is the actual method that will be called recursively for dfs exploration. 
  void dfsTree(int start, vector<bool> &vis) {
    if(vis[start]){
      return;
    }
    vis[start] = true;
    cout<<start<<" ";
    for(int v: adj[start]){
      if(vis[start]) continue;
      dfsTree(v,vis);
    }
    return ;
  }
  
  // OPTIONAL. YOU CAN IGNORE THIS IF YOU WANT. 
  // Solve using dfs (or any other method you know). 
  bool dfsCyclic(int start,int parent , vector<int> &vis){
    vis[start] = true;
    for(int nbr : adj[start]){
      if(!vis[nbr]){
        bool t = dfsCyclic(nbr, start, vis);
        if(t)
          return t;
      }
      else if(nbr!=parent){
          return true;
      }
    }

    return false;
  }
  bool isCyclic() {
      vector<int> vis(N);
      for(int i=0;i<N;i++){
        if(!vis[i])
        {
          bool cycle = dfsCyclic(i,-1,vis);
          if(cycle) return true;
        }
      }
    return false;
  }
  
  // Return vector with all nodes in topological order. If not possible, return empty vector. 
  void topoSort(int start, vector<bool> &vis, vector<int> &topoStack){
    vis[start] = true;
    for(auto nbr: adj[start]){
      if(!vis[nbr]) topoSort(nbr,vis,topoStack);
    }
    topoStack.push_back(start);
    return ;
  }
  vector<int> topologicalSort() {
    vector<bool> vis(N);
    vector<int> topoStack;
    for(int i=0;i<N;i++){
      if(!vis[i])
        topoSort(i,vis,topoStack);
    }
    reverse(topoStack.begin(),topoStack.end());
    return topoStack;
  }
  
  // For implementation, this is the best shortest path algorithm to implement. Djikstra is difficult to implement. 
  // For an unweighted graph, compare the output of this with the BFS algorithm. 
  // Return shortest path to all nodes. 
  vector<int> bellmanFord(int start) {
    vector<int> d(N,INT_MAX);
    d[start] = 0;
    vector<int> parent(N,-1);
    parent[start] = start;
    for(int i=0;i<N;i++){
      for(int j=0;j<E;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if(d[u] != INT_MAX and d[u] + w < d[v])
        {  d[v] = d[u] + w;
          parent[v] = u;
        }
      }
    }

    for(int j=0;j<E;j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if(d[u] != INT_MAX and d[u] + w < d[v])
        {
          cout<<"There is a negative cycle in graph"<<endl;
          return {};
        }
    }

    for(int i=0;i<N;i++){
      cout<<"Shortest Path from "<<start<<" to "<< i<<endl;
      int end = i;
      while(parent[end] != end){
        cout<<end<<" -> ";
        end = parent[end];
      }
      cout<<end<<endl;
    }

    return d;

  }
  
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
  int m; cin>>m; 
  // cout<<n<<endl;
  Graph adj = Graph(n,true,m);
  
  for(int i=0;i<m;i++){
    int u,v; cin>>u>>v;
    adj.addEdge(u,v);
  }

  adj.bfs(0);
  int source = 0;
  cout<<"Distance of all nodes from "<<source<<endl;
  vector<int> d = adj.getShortestDistanceToAllNodes(source);
  for(int i=0;i<d.size();i++){
    cout<<source<<" "<<i<<" = "<<d[i]<<endl;
  }
  adj.printBfsPath(0, 4);
  cin>>n>>m;
  Graph g = Graph(n,false,m);
  for(int i=0;i<m;i++){
    int u,v; cin>>u>>v;
    g.addEdge(u,v);
  }
  vector<int> topo = g.topologicalSort();
  cout<<"Topological Sorting"<<endl;
  for(auto it:topo)
    cout<<it<<" ";
  cout<<endl;
  // Read text files using ifstream. You can refer learncpp.com for this.
  
  // Assignment 2: 
  // Now add weights to your edges and read the weighted graph in your adjacency matrix. 
  // Run bellman ford algorithm to print shortest paths. 
  cin>>n>>m;
  Graph graphW = Graph(n,false,m);
  for(int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w;
    graphW.addEdgeW(u,v,w);
  }
  
  vector<int>wd = graphW.bellmanFord(0);
  for(int i=0;i<wd.size();i++){
    cout<<"Distance from "<<source<<" to "<<i<<" = "<<wd[i]<<endl;
  }




  
}
