#include <iostream>
#include "helpermethods.cpp"

using namespace std; 

TreeNode * search(TreeNode * root, int key) { // 8, 3, 1, NULL
	if(root == NULL) {
		return root; 
	}
	if(root->val == key) {
		return root; 
	}
	else if(key < root->val) {
		return search(root->left, key);  
	}
	else if(key >= root->val) {
		return search(root->right, key);
	}
	return NULL; 
}


TreeNode * insert1(TreeNode * root, int key) {
	if (root == NULL) {
		TreeNode * temp = new TreeNode(key); 
		return temp;
	}
	if(key < root->val) {
		root->left = insert1(root->left, key); 
	}
	else if(key >= root->val) {
		root->right = insert1(root->right, key); 
	}
	return root; 
}

// key = 2
TreeNode *insert2(TreeNode *root, int key) { // 8
	TreeNode * temp = new TreeNode(key);
	if(root == NULL) {
		return temp; 
	}
	TreeNode * curr = root, *parent = NULL; 
	while(curr!=NULL) {
		if(key < curr->val) {
			parent = curr; 
			curr = curr->left;
		}
		else { // key >= curr->val
			parent = curr; 
			curr = curr->right; 
		}
	}
	if (key < parent->val) {
		parent->left = temp; 
	}
	else {
		parent->right = temp; 
	}
	return root;
}


// min value in the RIGHT subtree. 
TreeNode * minValue(TreeNode * root) {
 	if(root == NULL || root->left == NULL) {
//	if(root->left == NULL || root == NULL) {
		return root; 
	}
	while(root->left != NULL) {
		root = root->left;
	}
	return root; 
}



TreeNode *maxValue(TreeNode * root) {
	if(root == NULL) {
		return root; 
	}
	while(root->right!=NULL) {
		root = root->right; 
	}
	return root; 
}


// Simple test cases: 
// key = 11
TreeNode * predecessor(TreeNode * root, int key) {
	if(root == NULL) {
		return NULL; 
	}
	TreeNode * curr = root, * pred = NULL;
	// 1. evaluate that node: 
	// 	a. Can this node be the predecessor of key? 
	//  b. pred = node
	while(curr!=NULL) { // 8, 10 (pred), 14, 13, NULL
		if(key <= curr->val) {
			curr = curr->left; 
		}
		else if(key > curr->val) {
			pred = curr;
			curr = curr->right; 
		}
	}
	return pred; 
}


TreeNode * successor (TreeNode * root, int key) {
	if(root == NULL) {
		return NULL; 
	}
	TreeNode * curr = root, *succ = NULL; 
	// 1. Traverse the tree using the key
	// At each node, ask: 
	// a. Can this node be the successor of key? 
	while(curr!=NULL) {
		if(key < root->val) {
			succ = curr; 
			curr = curr->left; 
		}
		else if(key >= root->val) {
			curr = curr->right; 
		}
	}
	return succ; 
}

// key = 50
TreeNode * deleteNode(TreeNode * root, int key) {
	if(root == NULL) {
		return root; 
	}
	if(root->val == key) {
		// Case 1: Node has no children
		if(root->left == NULL && root->right == NULL) {
			return NULL;
		}
		else if(root->left == NULL || root->right == NULL) {
			TreeNode * temp = (root->left == NULL) ? root->right : root->left;
			return temp;
		}
		else {
			TreeNode * nextLargest = minValue(root->right); 
			root->val = nextLargest->val; // 50 has been replaced with 60. 
			root->right = deleteNode(root->right, nextLargest->val); // 60
			return root; 
		}
	}
	else if(key < root->val) {
		root->left = deleteNode(root->left, key); 
	}
	else { // key >= root->val
		root->right = deleteNode(root->right, key); 
	}
	return root; 
}


TreeNode * lca(TreeNode * root, int lkey, int rkey) {
	if(root == NULL) {
		return NULL;
	}
	if(root->val == lkey || root->val == rkey) {
		return root; 
	}
	TreeNode * lanswer = lca(root->left, lkey, rkey); 
	TreeNode * ranswer = lca(root->right, lkey, rkey); 
	if(lanswer != NULL && ranswer!=NULL){
		return root; 
	}
	else if(lanswer != NULL || ranswer!=NULL ) {
		return (lanswer == NULL? ranswer : lanswer); 
	}
	// both lanswer and ranswer are null. 
	return NULL; 
}


int height(TreeNode * root) {
	if(root == NULL) {
		return 0; 
	}
	int lh = height(root->left); 
	int rh = height(root->right); 
	return 1 + max(lh, rh); 
}


int diameter(TreeNode * root, int& maxLen) {
	if(root == NULL) {
		return 0;
	}
	int lh = diameter(root->left, maxLen); 
	int rh = diameter(root->right, maxLen);

	maxLen = max(maxLen, lh + rh + 1);
	return 1 + max(lh, rh); 
}

int main() {
	// TreeNode * root = generateBST(10); 
	// TreeNode * curr = search(root, 44); 
	// cout<<curr->val<<endl;
	vector<int> v = generateRandomArray(5); 
	TreeNode * newTree = NULL; 
	newTree = insert1(newTree, 15);
	cout<<"Newtree: "<<endl;
	for(int i = 0;i<v.size();i++) {
		newTree = insert2(newTree, v[i]); 
	}
	printTree(newTree); 
	newTree = deleteNode(newTree, 15); 
	printTree(newTree);

	int diameterVal = 0; 
	diameter(newTree, diameterVal);
	cout<<diameterVal<<endl;
}
	// printTree(newTree); 
	// // Find max and min values. 
	// cout<<maxValue(newTree)->val<<endl;
	// cout<<minValue(newTree)->val<<endl;
	// cout<<"Find successor of each element: "<<endl;
	// for(int i = 0;i<v.size();i++) {
	// 	cout<<v[i]<<": "<<successor(root, v[i])->val<<" ";
	// }
	// cout<<endl;
	// cout<<"Find predecessor of each element: "<<endl;
	// for(int i = 0;i<v.size();i++) {
	// 	cout<<v[i]<<": "<<predecessor(root, v[i])->val<<" ";
	// }
	// cout<<endl;