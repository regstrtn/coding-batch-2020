#include<iostream>
#include<vector> 

using namespace std; 

// My personal hack for heap = never start filling from position 0 in the array. 
// Always start from position 1. 
class minHeap {
  public: 
  int size; 
  vector<int> v; 
  
  minHeap(size) {
    v.resize(size+1); 
  }
  
  minHeap(vector<int> inp) {
    size = inp.size(); 
    v.push_back(-1); 
    for(int i = 0; i<size; i++) {
      v.push_back(inp[i]); 
  }
  
  
};
