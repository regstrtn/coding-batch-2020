#include<iostream>
#include<vector> 

using namespace std; 

// My personal hack for heap = never start filling from position 0 in the array. 
// Always start from position 1. 
class minHeap {
  public: 
  
  int capacity; 
  // Due to our hack. size = index of last element in heap. 
  int size; 
  // Initially this vector will be filled with elements by the caller. 
  // Start filling from index 1; 
  vector<int> arr;  
  
  minHeap(capacity) {
    this->capacity = capacity. 
    arr.resize(capacity+1); 
  }
  
  // Start calling bubbleDown on every index starting from size/2 to 1. Why? 
  void minHeapify() {
    
  }
  
  // Save first element in temp. Then swap first element with arr[size]. 
  // Reduce size by 1. Call bubble down on arr[0]. Return temp. 
  int extractMin() {
    
  }
  
  // The following three conditions are only true if you fill from index 1; 
  int parent(int i) {
    return i/2; 
  }
  
  int left(int i) {
    return 2*i; 
  }
  
  int right (int i){
    return 2*i + 1; 
  }
  
  void bubbleUp(int i) {
  }
  
  void bubbleDown(int i) {
  }
  
  
  
};
