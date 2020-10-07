#include <iostream>
#include <vector> 
#include <algorithm>
#include <numeric>
#include "helpermethods.cpp"

using namespace std; 

int maxOf3(int a, int b, int c) {
	return max(max(a, b), c);
}

int findMaxValue(TreeNode * root) {
	if(root == NULL) {
		return INT_MIN; 
	}
	int leftMax = findMaxValue(root->left);  // 6
	int rightMax = findMaxValue(root->right);  // 4
	return maxOf3(leftMax, rightMax, root->val); // 4, 5, 6
}

// int isLeaf(TreeNode *root) {
// 	return (root->left == NULL && root->right == NULL);
// }

// int height(TreeNode * root) {
// 	// if(root == NULL) {
// 	// 	return 0; 
// 	// }
// 	if(isLeaf(root)) {
// 		return 1; 
// 	}
// 	int lh = height(root->left); 
// 	int rh = height(root->right); 
// 	return max(lh, rh) + 1;
// }



// // Traversal
// void preorder(TreeNode * root, vector<int> &v) {
// 	if(root == NULL) {
// 		return; 
// 	}
// 	v.push_back(root->val); 
// 	traverseTree(root->left, v);
// 	traverseTree(root->right, v);
// }

// // Traversal
// void postorder(TreeNode * root, vector<int> &v) {
// 	if(root == NULL) {
// 		return; 
// 	}
// 	traverseTree(root->left, v);
// 	traverseTree(root->right, v);
// 	v.push_back(root->val); 
// }


// // Traversal. Binary search tree. 
// void inorder(TreeNode * root, vector<int> &v) {
// 	if(root == NULL) {
// 		return; 
// 	}
// 	traverseTree(root->left, v);
// 	v.push_back(root->val); 
// 	traverseTree(root->right, v);
// }

//  8
// 3

int isLeaf(TreeNode * root) {
	return (root->right == NULL && root->left == NULL);
}

void allPathSum(TreeNode * root, int sum) {
	if(isLeaf(root)) {
		cout<<sum + root->val <<endl; 
	}
	// At node 3, what recursive calls will be made. 
	allPathSum(root->left, sum + root->val); 
	allPathSum(root->right, sum + root->val); 
}


int main() {
	// TreeNode * root = new TreeNode(); 
	// // Construct tree. 
	// int maxValue = findMaxValue(root); 
	// cout<<maxValue<<endl;
	TreeNode * root = generateBST(5); 
	allPathSum(root, 0);
}

