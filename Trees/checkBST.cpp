/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
*/
#include<bits/stdc++.h>
using namespace std;
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

bool check(Node* root, int minimum, int maximum){
	if(root==NULL) return true;
	if(root->data <=minimum || root->data >= maximum) return false;
	if((root->left == NULL || (root->left)->data < root->data )&& 
		(root->right == NULL || (root->right)->data > root->data)){
		return (check(root->left, minimum, min(maximum, root->data)) && 
				check(root->right, max(minimum, root->data),maximum));
	}
	return false;
}
bool checkBST(Node* root) {
	return check(root,0,INT_MAX);
}