#include<bits/stdc++.h>
using namespace std;

class binarySearchTreeNode{
	public:
	int value;
	binarySearchTreeNode* left;
	binarySearchTreeNode* right;
	binarySearchTreeNode(int value){
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	void add(int value, binarySearchTreeNode* root){
		if(value < root->value){
			if(root->left==NULL){
				binarySearchTreeNode* node = new binarySearchTreeNode(value);
				root->left = node;
			}else{
				add(value, root->left);
			}
		}else{
			if(root->right==NULL){
				binarySearchTreeNode* node = new binarySearchTreeNode(value);
				root->right = node;
			}else{
				add(value, root->right);
			}
		}
	}
	void print_in_order(binarySearchTreeNode* root){
		if(root==NULL)
		return;
		print_in_order(root->left);
		cout<<root->value<<endl;
		print_in_order(root->right);
	}
	void print_pre_order(binarySearchTreeNode* root){
		if(root==NULL)return;
		cout<<root->value<<endl;
		print_pre_order(root->left);
		print_pre_order(root->right);
	}
	void print_post_order(binarySearchTreeNode* root){
		if(root==NULL)return;
		print_post_order(root->left);
		print_post_order(root->right);
		cout<<root->value<<endl;
	}
};

int main(){
binarySearchTreeNode* root = new binarySearchTreeNode(5);
root->add(10,root);
root->add(15,root);
root->add(1,root);
root->print_in_order(root);
root->print_post_order(root);
root->print_pre_order(root);
return 0;
}