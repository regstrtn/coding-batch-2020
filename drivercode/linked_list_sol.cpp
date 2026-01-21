// Linkedlist Driver Code 

// Write include statements. 
#include <bits/stdc++.h>

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
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


// Return an array of random integers of the given size. 
vector<int> generateRandomArray(int size ){
    vector<int> arr(size);
    for(int i=1;i<=size;i++){
        arr[i-1] = rand() % 117;
    }
    sort(arr.begin(),arr.end());
  return arr; 
}


// Convert array to linkedlist
Node * convertArrayToLinkedList(vector<int> & v) {
    
   Node* head =new Node();
   Node* temp = head;
   for(auto it:v){
       Node * temp = new Node(it);
       head->next = temp;
       head = head->next;
   } 
   return temp->next;
}



// Insert into a linked list at given position. Position = 1 means insert before head. 
Node * insertNode (Node * head, int val, int position) {
    if(position == 1 ){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    int cnt = 1;
    Node * temp = head;
    while(cnt!=position-1){
        temp = temp->next;
        cnt++;

    }
    Node* temp2 = new Node(val);
    temp2->next = temp->next;
    temp->next = temp2;

    

  return head; 
}


// Delete from a linked list. 
Node *deleteNode (Node * head, int position) {
    if(position == 1){
        return head->next;
    }
    if(head->next == NULL){
        Node *temp = new Node();
        return temp;
    }
    int cnt = 1;
    Node * temp = head;
    while(cnt != position-1){
        temp = temp->next;
        cnt++;
    }
    temp->next = temp->next->next;


 return head; 
}


// Compare linkedlists. 
bool areEqual(Node *head1, Node * head2) {
    while(head1 != NULL and head2 !=NULL){
        if(head1->val != head2->val)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1 != NULL or head2 !=NULL)
        return false;
  return true; 
}

// K = 1 means delete last node. 
Node *deleteKthNodeFromEnd(Node * head, int k) {
     Node * temp1 = head;
     Node* temp2 = head;
     
     while(k-- and temp1!=NULL){
         temp1 = temp1->next;
     }
     if(temp1 == NULL)
        return head->next;
     while(temp1->next != NULL){
         temp2 = temp2->next;
         temp1 = temp1->next;
     }
     temp2->next = temp2->next->next;

  return head; 
}



// Reverse a linkedlist. 
Node * reverseList(Node *head) {
    Node * next = head;
    Node* curr = head;
    Node * prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
  return prev; 
}

// Merge sorted lists. 
Node * mergeSortedLists(Node * head1, Node * head2) {
        Node *h1 = head1;
        if(head1->val < head2->val){
            head1 = head1->next;
        }
        else{
            h1 = head2;
            head2 = head2->next;
        }
        Node* temp = h1;
        while(head1 != NULL and head2 != NULL){
            if(head1->val < head2->val){

                h1->next = head1;
                h1 = h1->next;
                head1 = head1->next;
            }
            else{
                h1->next = head2;
                h1 = h1->next;
                head2 = head2->next;
            }
        }
        while(head1 != NULL){
            h1->next = head1;
            head1 = head1->next;
            h1 = h1->next;
        }
        while(head2 != NULL){
            h1->next = head1;
            head2 = head2->next;
            h1 = h1->next;
        }

return temp; 
}

int main() {
  // 1. Get a random array. 
  // 2. Convert array to LinkedList List1.
  // 3. Insert a number at position P into the list.
  // 4. Delete this number from position P. 
  // 5. Create another linkedlist (List2) from the same random array. 
  // 6. Compare that List1 is the same as List2. 

  int size = 4;
  vector<int> arr = generateRandomArray(size);
  vector<int> arr2 = generateRandomArray(size+2);
  Node *head =  convertArrayToLinkedList(arr);
  Node *head2 =  convertArrayToLinkedList(arr2);
//   printList(head);
//   head = insertNode(head,312,11);
//   printList(head);
//   head = deleteNode(head,10);
  printList(head);
  printList(head2);
//   printList(head2);
//   cout<< areEqual(head,head2)<<endl;
    // head = deleteKthNodeFromEnd(head, 10);
    // printList(head);
    // head = reverseList(head);
    head2 = mergeSortedLists(head,head2);
    printList(head2);
  
  
}