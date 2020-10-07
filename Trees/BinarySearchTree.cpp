#include <iostream>
#include "helpermethods.cpp"

using namespace std; 

// class TreeNode {
// public: 
// 	int val; 
// 	TreeNode * left; 
// 	TreeNode * right; 
// 	TreeNode(int val) {
// 		this->val = val; 
// 	}
// };

TreeNode* search(TreeNode* root, int key) 
{ 
    if (root == NULL) {
    	return root; 
    } 
    if(root->val == key) 
       return root; 
     
    if (key < root->val)  
       return search(root->left, key); 
  
    return search(root->right, key); 
} 

// TreeNode * insert(TreeNode * root, int val) {
// 	TreeNode * newNode = new TreeNode(val); 
// 	if(root == NULL) {
// 		// tree is empty
// 		return newNode; 
// 	}
// 	TreeNode * curr = root, *parent = NULL; 
// 	while(curr!=NULL) {
// 		parent = curr; 
// 		if(val < curr->val) {
// 			curr = curr->left; 
// 		}
// 		else {
// 			curr = curr->right; 
// 		}
// 	}
// 	if(val < parent->val) {
// 		parent->left = newNode; 
// 	}
// 	else parent->right = newNode; 
// 	return root; 
// }

TreeNode* insert(TreeNode* root, int key) 
{ 
    if (root == NULL) return(new TreeNode(key));
  
    if (key < root->val) 
        root->left  = insert(root->left, key); 
    else if (key > root->val) 
        root->right = insert(root->right, key);
    return root; 
} 


TreeNode * minValue(TreeNode * root) {
	if(root == NULL) {
		return NULL; 
	}
	if(root->left) {
		return minValue(root->left); 
	}
	return root; 
}

TreeNode *  maxValue(TreeNode * root) {
	if(root == NULL) {
		return NULL; 
	}
	if(root->right) {
		return maxValue(root->right); 
	}
	else {
		return root; 
	}
}

TreeNode * successor(TreeNode * root, int key) {
	if(root == NULL) {
		return new TreeNode(-1); 
	}
	TreeNode * succ = new TreeNode(-1), *curr = root; 
	while(curr!=NULL) {
		if(key < curr->val) {
			succ = curr; 
			curr = curr->left; 
		}
		else if(key >= curr->val) {
			curr = curr->right; 
		}
	}
	return succ; 
}

TreeNode * predecessor(TreeNode * root, int key) {
	if(root == NULL) {
		return new TreeNode(-1); 
	}
	TreeNode * pred = new TreeNode(-1), *curr = root; 
	while(curr!=NULL) {
		if(key > curr->val) {
			pred = curr; 
			curr = curr->right; 
		}
		else if(key <= curr->val) {
			curr = curr->left; 
		}
	}
	return pred; 
}

int main() {
	TreeNode * root = generateBST(10); 
	TreeNode * curr = search(root, 44); 
	cout<<curr->val<<endl;
	vector<int> v = generateRandomArray(10); 
	TreeNode * newTree = NULL; 
	for(int i = 0;i<v.size();i++) {
		newTree = insert(newTree, v[i]); 
	}
	printTree(newTree); 
	// Find max and min values. 
	cout<<maxValue(newTree)->val<<endl;
	cout<<minValue(newTree)->val<<endl;
	cout<<"Find successor of each element: "<<endl;
	for(int i = 0;i<v.size();i++) {
		cout<<v[i]<<": "<<successor(root, v[i])->val<<" ";
	}
	cout<<endl;
	cout<<"Find predecessor of each element: "<<endl;
	for(int i = 0;i<v.size();i++) {
		cout<<v[i]<<": "<<predecessor(root, v[i])->val<<" ";
	}
	cout<<endl;
}