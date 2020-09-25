#include <iostream>
#include <cstddef>
#include<bits/stdc++.h>	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  
    void preOrder(Node *root) {

          if( root == NULL )
              return;

          std::cout << root->data << " ";

          preOrder(root->left);
          preOrder(root->right);
      }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/



    Node * insert(Node * root, int data) {
		if(root==NULL){
			Node* temp = new Node(data);
			root = temp;
		}else if(root->left==NULL && data < root->data){
            Node* temp = new Node(data);
            temp->left = temp->right = NULL;
            root->left = temp;
        }else if(root->right==NULL && data > root->data){
            Node* temp = new Node(data);
            root->right = temp;
        }else if(root->data>data){
            insert(root->left, data);
        }else if(root->data<data){
            insert(root->right, data);
        }
        return root;
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;
	std::cout<<"test"<<"\n";
    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
	myTree.preOrder(root);
    return 0;
}
