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
		left=right=nullptr;
	}
};

// 1.creating BT
Node* createBT(){
	Node* root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	return root;
}

int main(){
	// 1.creating BT
	Node* root = createBT()	;
}