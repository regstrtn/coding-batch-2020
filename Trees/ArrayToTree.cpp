#include <iostream>
#include <vector> 
#include <algorithm>
#include <numeric>
#include "helpermethods.cpp"

using namespace std; 

class TreeNode {
public:
	int val; 
	TreeNode * left; 
	TreeNode * right; 
	TreeNode(int val) {
		this->val = val; 
		this->right = NULL; 
		this->left = NULL; 
	}
};


TreeNode* buildTree(vector<int> &v, int start, int end) {
	// base case
	if(start > end) {
		return NULL;
	}
	// recursive case
	int mid = (start + end)/2;
	int val = v[mid]; 
	TreeNode * root = new TreeNode(val); 
	root->left = buildTree(v, start, mid-1); 
	root->right = buildTree(v, mid+1, end); 
	return root; 
}


// Traversal
void preorder(TreeNode * root) {
	if(root == NULL) {
		return; 
	}
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

// Traversal
void postorder(TreeNode * root) {
	if(root == NULL) {
		return; 
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}


// Traversal. Binary search tree. 
void inorder(TreeNode * root) {
	if(root == NULL) {
		return; 
	}
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main() {
	vector<int> v = generateSortedArray(10); 
	cout<<"Sorted array: "; 
	printArray(v); 
	TreeNode * root = buildTree(v, 0, v.size()-1);
	cout<<"Inorder traversal: "; 
	inorder(root);
	cout<<endl<<"Preorder traversal: "; 
	preorder(root); 
	cout<<endl<<"Postorder traversal: "; 
	postorder(root); 	
}





