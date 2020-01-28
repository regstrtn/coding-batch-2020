//Language C++


#include <iostream>
//Include other libraries
using namespace std; 



// Insert at the end of linked list

Node * insert(Node * head, int data) {
	//Is head null

}


//Write the code for finding maximum element in a tree
//Return the node itself

class TreeNode {
public: 
	int val; 
	TreeNode * left; 
	TreeNode * right; 
}


TreeNode * maxElement(TreeNode * root) {
	if(root == NULL) return NULL; 
	TreeNode * parent, * curr; 
	curr = root; 
	parent = NULL; 
	while(curr!=NULL) {
		parent = curr; 
		curr = curr->right; 
	}
	return parent; 
}




int main() {
	//some code here

	TreeNode * maxNode = maxElement(root); 
	if(maxNode!=NULL) 
		int maxval = maxNode->val; 
	
	//some code here
}

//27 Jan

TreeNode * insert(TreeNode * root, int key) {

	TreeNode * newNode = new TreeNode(key); 

	newNode->left = newNode->right = NULL; 
	if(root == NULL) return newNode;

	TreeNode * curr = root, * parent = NULL; 
	
	while(curr!=NULL) {
		parent = curr; 
		if(key > curr->val) curr = curr->right; 
		else curr = curr->left;
	}
	if(key < parent->val) parent->left = newNode; 
	else parent->right = newNode; 
	return root; 

}


//Finding successor in a BST. Inorder successor in a Binary Search Tree.
//Case 1: Node does not have a right subtree
//


TreeNode * getSuccessor(TreeNode * root, int key) {
	if(root == NULL) return NULL; 
	TreeNode * succ = NULL, *curr = root; 

	while(curr != NULL && curr->val!=key) {
		if(key < curr->val) {
			succ = curr; 
			curr = curr->left;
		}
		else {
			curr = curr->right; 
		}
	}
	//curr is pointing to our node. 
	if(curr!=NULL) curr = curr->right; 
	while(curr!=NULL) {
		succ = curr; 
		curr = curr->left; 
	}
	return succ; 
}

//Deleting the node

//Case 1: Leaf node
//Case 2: Single child
//Case 3: Double child

//Search a key and return the node
TreeNode * searchKey(TreeNode *root, int val) {
	if(root == NULL) return NULL; 
	TreeNode * curr = root; 
	while(curr!=NULL) {
		if(curr->val == val) return curr; 
		if(val > curr->val) curr = curr->right; 
		else curr = curr->left; 
	}
	return curr; 
}


//Search parent
TreeNode * parentKey(TreeNode * root, int val) {
	if(root == NULL) return NULL; 
	TreeNode * parent = NULL, * curr = root; 
	//root node does not have a parent
	if(root->val == val) return NULL; 

	while(curr!=NULL) {
		if(curr->val == val) {
			return parent; 
		}
		if(val > curr->val) {
			parent = curr; 
			curr = curr->right; 
		}
		else {
			parent = curr; 
			curr = curr->left; 
		}
	}
	return parent; 
}


TreeNode * deleteNode (TreeNode * root, int key) {
	if(root == NULL) return NULL; 
	TreeNode * k = searchKey(root, key); 
	TreeNode * parent = parentKey(root, key); 

	//both false
	if(k->left == NULL && k->right == NULL) {
		//Leaf node case
		if(parent == NULL) return NULL; //checking for root;
		if(parent->left == k) parent->left = NULL; 
		else parent->right = NULL;
		delete k; 
		return root; 
	}

	//both true
	else if(k->left && k->right) {
		//Both children present
		TreeNode * succ = getSuccessor(root, k->val);
		int succVal = succ->val;  
		deleteNode(root, succ->val);
		k->val = succVal; 
		return root; 
	}	
	//one of them may be true
	else {
		//One child present
		TreeNode * nodeToRetain = k->left ? k->left : k->right; 
		if(parent == NULL) return nodeToAttach; 
		if(parent->left == k) parent->left = nodeToAttach; 
		else parent->right = nodeToAttach; 
		return root; 
	}
}


///What can we do in a tree? 
// 1. Parent pointer is NOT THERE. 

// What is there in a Tree? 
// 1. We can update a global variable. 
// 2. Return a value from every node.
// 3. Can access the value of the node.
// 4. Access the subtree of that node.

//Find the maximum value in a binary tree. (Not a BST)

//global variable update

void findMax(TreeNode * root, int & maxVal) {
	if(root == NULL) return; 
	maxVal = max(maxVal, root->val); 
	findMax(root->left, maxVal); 
	findMax(root->right, maxVal);
}


int findMax(TreeNode * root) {
	if(root == NULL) return INT_MIN; 
	int leftMax = findMax(root->left); 
	int rightMax = findMax(root->right); 
	int M = max(root->val, max(leftMax, rightMax)); 
	return M; 
}


//Diameter of a binary tree
int globalD = INT_MIN; 

int height(TreeNode * root) {
	if(root == NULL) return 0; 
	int lh = height(root->left); 
	int rh = height(root->right); 
	return 1+max(lh, rh); 
}

void findDiameter(TreeNode * root) {
	if(root == NULL) return; 
	int lh = height(root->left); 
	int rh = height(root->right); 
	int currentD = lh+rh+1; 
	globalD = max(globalD, currentD); 
}


Time complexity : O(n2)

int main() {

}
