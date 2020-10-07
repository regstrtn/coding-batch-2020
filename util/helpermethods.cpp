#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "helpermethods.h"

using namespace std; 



void printArray(vector<double> & v) {
	int i = 0; 
	for(i=0;i<v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void printArray(vector<int> & v) {
	int i = 0; 
	for(i=0;i<v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void printArray(vector<string> & v) {
	int i = 0;
	for(i=0;i<v.size();i++) {
		cout<<v[i]<<endl;
	}
}

vector<int> generateRandomArray(int size) {
	srand(10); 
	vector<int> v(size, 0); 
	const int MAX_VALUE = size*10;
	int i = 0; 
	for(i=0;i<size;i++) {
		// We don't want any zero values in arrays. 
		v[i] = rand()%MAX_VALUE + 1; 
	}
	cout<<"Random Array: "; 
	printArray(v); 
	return v; 
}

vector<int> generateSortedArray(int size) {
	vector<int> v = generateRandomArray(size); 
	sort(v.begin(), v.end()); 
	return v; 
}


bool checkArraySorted(vector<int> & v) {
	int i = 0;
	if(v.size() <= 1) {
		return true; 
	} 
	for(i=0;i<v.size()-1;i++) {
		if(v[i] > v[i+1]) {
			cout<<"Array is not sorted."<<endl;
			return false; 
		}
	}
	cout<<"Array Sorted."<<endl;
	return true; 
}

TreeNode* _buildTree(vector<int> &v, int start, int end) {
	// base case
	if(start > end) {
		return NULL;
	}
	// recursive case
	int mid = (start + end)/2;
	int val = v[mid]; 
	TreeNode * root = new TreeNode(val); 
	root->left = _buildTree(v, start, mid-1); 
	root->right = _buildTree(v, mid+1, end); 
	return root; 
}

// Preorder Traversal.
void preorder(TreeNode * root) {
	if(root == NULL) {
		return; 
	}
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

// Inorder traversal. 
void inorder(TreeNode * root) {
	if(root == NULL) {
		return; 
	}
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void printTree(TreeNode * root) {
	cout<<"Inorder: "; inorder(root); 
	cout<<endl;
	cout<<"Preorder: "; preorder(root); 
	cout<<endl;
}

TreeNode * generateBST(int size) {
	vector<int> v = generateSortedArray(size); 
	TreeNode * root = _buildTree(v, 0, v.size()-1);
	cout<<"Generated Tree: "<<endl;
	printTree(root);
	return root; 
}


