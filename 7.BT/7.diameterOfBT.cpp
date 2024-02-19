#include<bits/stdc++.h>
using namespace std;

class Node{
public:	
	int data;
	Node* left;
	Node* right;
public:
	Node(int value){
		data = value;
		left = right = nullptr;
	}

};

Node* createBT(){
	Node* root =  new Node(4);

	root->left = new Node(7);
	root->right = new Node(8);

	root->right->left = new Node(1);
	root->right->right = new Node(0);

	root->right->left->left = new Node(3);
	root->right->left->right = new Node(5);

	root->right->left->right->left = new Node(15);


	return root;
}

int diameter = -1;

int findLength(Node* node){
	if(!node) return 0;

	int lh = findLength(node->left);
	int rh = findLength(node->right);

	if(lh+rh > diameter) {

		diameter = lh+rh;
	}

	return 1+max(lh,rh);
}

void findDiameter(Node* root){
	int ans = findLength(root);
}

int main(){
	Node* root = createBT();

	findDiameter(root);
	cout << diameter;
}