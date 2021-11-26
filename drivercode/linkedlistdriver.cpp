// Linkedlist Driver Code 

// Write include statements. 
#include <iostream>
#include <string> 
#include<stdlib.h>
#include <vector>

using namespace std;

// Linkedlist node
class Node {
  public: 
  int val; 
  Node * next; 
  Node () {
    this->next = NULL; 
  }
  Node(int val) {
    this->val = val; 
    this->next = NULL; 
  }
}; 


// Print linked list 
void printList(Node *head) {
}


// Return an array of random integers of the given size. 
vector<int> generateRandomArray(int size) {
//   	vector<int> v(size, 0); 
// 	const int MAX_VALUE = size*10;
// 	int i = 0; 
// 	for(i=0;i<size;i++) {
// 		// We don't want any zero values in arrays. 
// 		v[i] = rand()%MAX_VALUE + 1; 
// 	}

  return vector<int>(); 
}


// Convert array to linkedlist
Node * convertArrayToLinkedList(vector<int> & v) {
  return new Node(); 
}

// Insert into a linked list at given position. Position = 1 means insert before head. 
Node * insertNode (Node * head, int val, int position) {
  return head; 
}


// Delete from a linked list. 
Node *deleteNode (Node * head, int position) {
 return head; 
}


// Compare linkedlists. 
bool areEqual(Node *head1, Node * head2) {
  return true; 
}

// K = 1 means delete last node. 
Node *deleteKthNodeFromEnd(Node * head, int k) {
  return head; 
}



// Reverse a linkedlist. 
Node * reverseList(Node *head) {
  return head; 
}

// Merge sorted lists. 
Node * mergeSortedLists(Node * head1, Node * head2) {
return head1; 
}

int main() {
  // 1. Get a random array. 
  // 2. Convert array to LinkedList List1.
  // 3. Insert a number at position P into the list.
  // 4. Delete this number from position P. 
  // 5. Create another linkedlist (List2) from the same random array. 
  // 6. Compare that List1 is the same as List2. 
  
  
}
