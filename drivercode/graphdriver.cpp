#include<iostream>
#include<fstream>
#include<vector> 

using namespace std; 

class Graph {
  public:
  
  int N; 
  vector<vector<int>> adj; // adjacency matrix. 
  
  Graph(int nodes) {
    N = nodes;
    adj.resize(N, vector<int> ()); 
  }
  
  // Directed graph. Make sure nodes are zero indexed. 
  void addEdge(int u, int v) {
    
  }
  
  // Write BFS Code. 
  void bfs(int start) {
  }

  // Print shortest path from start node to end node.  
  void printBfsPath(int start, int end) {
  }
  
  // use bfs.
  vector<int> getShortestDistanceToAllNodes(int start) {
  }
  
  // Why dfsForest? Because the graph may not be connected. 
  void dfsForest(int start) {
  }
  
  // This is the actual method that will be called recursively for dfs exploration. 
  void dfsTree(int start) {
  }
  
  // Solve using dfs (or any other method you know). 
  bool isCyclic() {
  }
  
  // Return vector with all nodes in topological order. If not possible, return empty vector. 
  vector<int> topologicalSort() {
  }
  
  // For implementation, this is the best shortest path algorithm to implement. Djikstra is difficult to implement. 
  // For an unweighted graph, compare the output of this with the BFS algorithm. 
  // Return shortest path to all nodes. 
  vector<int> bellmanFord(int start) {
  }
  
};

int main() {
  
  // Assignment 1: 
  // Create a text file that contains : (1) Number of nodes, and (2) List of edges. 
  // Read this edge list from the text file. 
  // Complete the methods above and run all methods on the graph you built in your text file. 
  // Try with disconnected graph, cyclic graph etc. 
 
  
  // Read text files using ifstream. You can refer learncpp.com for this.
  
  // Assignment 2: 
  // Now add weights to your edges and read the weighted graph in your adjacency matrix. 
  // Run bellman ford algorithm to print shortest paths. 
}
