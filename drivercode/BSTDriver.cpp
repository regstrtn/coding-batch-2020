// Driver code for a binary search tree. 

#include<iostream>
#include<vector>
#include<stdlib.h>
#include <algorithm> 
#include <queue>

using namespace std; 

class TreeNode {
  public: 
  int val; 
  TreeNode * left; 
  TreeNode * right;
 
  // Add constructor.
  TreeNode(){
    
    this->right = this->left  = NULL;
  } 
  TreeNode(int val){
    this->val = val;
    this->right = this->left  = NULL;
  }
}; 

vector<int> generateRandomArray(int size) {
  vector<int> arr(size);
  for(int i=0;i<size;i++){
    arr[i] = rand() % 117;
  }
  return arr; 
}

int height(TreeNode * root) {
  if(root == NULL)
    return 0;
  return max(height(root->left),height(root->right)) + 1;
  
}
void inorder(TreeNode* root){
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->val<<" ";
  inorder(root->right);
  return;
}
void preorder(TreeNode* root){
  if(root == NULL)
    return;
  cout<<root->val<<" ";
  preorder(root->left);
  preorder(root->right);
  return;
}
void postorder(TreeNode * root){
  if(root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->val<<" ";
  return;
}
void printTraversals(TreeNode * root) {
  // print inorder
  cout<<"Inorder"<<endl;
  inorder(root);
  cout<<endl;
  // print preorder
  cout<<"Preorder"<<endl;
  preorder(root);
  cout<<endl;
  // print postorder
  cout<<"Postorder"<<endl;
  postorder(root);
  cout<<endl;
  return;
}


// Return NULL if val not found. 
TreeNode * search(TreeNode * root, int val) {
  if(root == NULL)
    return root;
  if(root->val == val)
    return root;
  if(root->val > val)
    return search(root->left, val);
  
  return search(root->right, val); 
}

// Return parent even if val is not present in tree. 
// Basically return the parent of the location where val should have been.
TreeNode* searchParent(TreeNode * root, int val) {
  if(root == NULL)
    return root;
  
  if(root->left != NULL and root->left->val == val)
    return root;
  if(root->right != NULL and root->right->val == val)
    return root;
  if(root->val>val)
    return searchParent(root->left,val);
  return searchParent(root->right,val);
}


TreeNode * insert(TreeNode * root, int val) {
  if (root == NULL) {
      TreeNode* t=new TreeNode(val); 
      return t;
    }
 
    
    if (val< root->val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
 
    return root;


}
 
int maxValue(TreeNode * root) {
  if(root->right == NULL)
    return root->val;
  
  return maxValue(root->right); 
}

int minValue(TreeNode * root) {
  if(root->left == NULL)
    return root->val;
  
  return minValue(root->left);
}

// Return NULL if val has no successor, ie, val is greater than maxValue(root);  
// Successor should be returned even if val is not present in the tree. 
TreeNode * findSuccessor(TreeNode * root,TreeNode* Root) {
  
  if(root == NULL)
  { return root;}
  if(root->right)
    return search(root->right,minValue(root->right));
  TreeNode * t = searchParent(Root,root->val);
  while( t!=NULL and root == t->right){
    root = t;
    t = searchParent(Root,root->val);
  }
  return t;
}

// Return NULL if val has no predecessor, ie, val is smaller than minValue(root);  
// Predecessor should be returned even if val is not present in the tree. 
TreeNode * findPredecessor(TreeNode * root,TreeNode* Root) {
  if(root == NULL)
    return root;
  if(root->left)
    return search(root->left,maxValue(root->left));
  TreeNode * t = searchParent(Root,root->val);
  while( t!=NULL and root == t->left){
    root = t;
    t = searchParent(Root,root->val);
  }
  return t;
}

// Return the lowest common ancestor. 
TreeNode * lowestCommonAncestor(TreeNode * root, int val1, int val2) {
  
}

// First generate random array. Then build this tree by calling insert() on each element of array. 
TreeNode * buildTree(vector<int> & v) {
  // Call insert() repeatedly to build the tree.
  TreeNode* root = NULL;
  for(auto it:v)
  { 
    root = insert(root,it);
  }
  return root;
}
void LevelOrderBFS(TreeNode* root){
  if(root == NULL)
    return ;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    TreeNode* temp = q.front();
    q.pop();
    if(temp == NULL)
    {
      cout<<"\n";
      if(!q.empty())
        q.push(NULL);
    }
    else{
      cout<<temp->val<<" ";
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);

    }
    
  }
  return;
}


int main() {
  // Study all tree algorithms from geeksforgeeks or this youtube video. 
  // https://www.youtube.com/watch?v=K6nw5TvhX2s&list=PLrYpW0KwQ3sMemsZOzhawxMpFet3Hb3SN&index=39

  // 1. Generate a random array. 
  vector<int> arr = generateRandomArray(10);
  for(auto it:arr)
    cout<<it<<" ";
  cout<<"\n";
  // 2. Create an empty tree and insert one value from the array at a time.
  TreeNode* root = buildTree(arr);
   
  // 3. Inorder traversal of this binary search tree should be equal to the sorted value of random array.  
  printTraversals(root); 
  // 4. Find the height of the tree. 
  // Level order
  cout<<"Level Order"<<"\n";
  LevelOrderBFS(root);
  cout<<"Height of tree : "<< height(root)<<" \n";
  
  // 5. Find the minimum value in the array.
  int mv = minValue(root); 
  cout<<"Min value in tree : "<<mv<<"\n";
  // 6. In the tree, find successor of this value. Print it. Then find successor
  TreeNode * temp = search(root,mv);
  
  TreeNode * succ = findSuccessor(temp,root);
  
  while(succ != NULL){
  cout<<"successor of "<<temp->val<<" is "<<succ->val<<" \n";
  temp = succ;
  succ = findSuccessor(temp,root);
  }

  //    of the value just obtained. Print again and so on. 
  // 7. This list should be equal to the sorted value of the array. 
  
  // 8. Find the maximum value in the array. 
  int mx = maxValue(root);
  cout<<"Max value in tree : "<<mx<<"\n";
  // 9. In the tree, find predecessor of this value. Print it. Then find predecessor
  //    of the value just obtained till no more predecessor exists. Print again and so on. 
  // 10. This list should be equal to the sorted value of the array. 
  temp = search(root,mx);
  TreeNode * psucc = findPredecessor(temp,root);
  while(psucc != NULL){
  cout<<"Presuccessor of "<<temp->val<<" is "<<psucc->val<<" \n";
  temp = psucc;
  psucc = findPredecessor(temp,root);
  }
  
  
}
