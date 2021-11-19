// Driver code for a binary search tree. 

#include<iostream>
#include<vector>
#include<stdlib.h>


using namespace std; 

class TreeNode {
  public: 
  int val; 
  TreeNode * left; 
  TreeNode * right; 
  // Add constructor. 
}; 

vector<int> generateRandomArray(int size) {
  return vector<int>(size); 
}

void printTraversals(TreeNode * root) {
  // print inorder
  // print preorder
  // print postorder
}


// Return NULL if val not found. 
TreeNode * search(TreeNode * root, int val) {
  return NULL; 
}

// Return parent even if val is not present in tree. 
// Basically return the parent of the location where val should have been.
TreeNode* searchParent(TreeNode * root, int val) {
  return NULL; 
}


TreeNode * insert(TreeNode * root, int val) {
  return root; 
}
 
int maxValue(TreeNode * root) {
  return INT_MAX; 
}

int minValue(TreeNode * root) {
  return INT_MIN; 
}

// Return NULL if val has no successor, ie, val is greater than maxValue(root);  
// Successor should be returned even if val is not present in the tree. 
TreeNode * findSuccessor(TreeNode * root) {
  return NULL;
}

// Return NULL if val has no predecessor, ie, val is smaller than minValue(root);  
// Predecessor should be returned even if val is not present in the tree. 
TreeNode * findPredecessor(TreeNode * root) {
  return NULL;
}

// First generate random array. Then build this tree by calling insert() on each element of array. 
TreeNode * buildTree(vector<int> & v) {
  // Call insert() repeatedly to build the tree.
  TreeNode * root = new TreeNode(); 
  return root; 
}

int main() {
  // Study all tree algorithms from geeksforgeeks or this youtube video. 
  // https://www.youtube.com/watch?v=K6nw5TvhX2s&list=PLrYpW0KwQ3sMemsZOzhawxMpFet3Hb3SN&index=39

  // 1. Generate a random array. 
  // 2. Create an empty tree and insert one value from the array at a time. 
  // 3. Inorder traversal of this binary search tree should be equal to the sorted value of random array.   
  // 4. Find the height of the tree. 
  
  
  // 5. Find the minimum value in the array. 
  // 6. In the tree, find successor of this value. Print it. Then find successor
  //    of the value just obtained. Print again and so on. 
  // 7. This list should be equal to the sorted value of the array. 
  
  // 8. Find the maximum value in the array. 
  // 9. In the tree, find predecessor of this value. Print it. Then find predecessor
  //    of the value just obtained till no more predecessor exists. Print again and so on. 
  // 10. This list should be equal to the sorted value of the array. 
  
  
}
