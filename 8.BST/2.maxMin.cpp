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

Node* createBST(){
	Node* root = new Node(8);

	root->left = new Node(5);
	root->right = new Node(12);

	root->left->left = new Node(4);
	root->left->right = new Node(7);

	root->left->right->left = new Node(6);

	root->right->left = new Node(10);
	root->right->right = new Node(14);

	root->right->right->left = new Node(13);

	return root;
}

int findMin(Node* node){
	while(node->left) node = node->left;

	return node->data;
}

int findMax(Node* node){
	while(node->right) node = node->right;

	return node->data;
}

int main(){
	Node* root = createBST();

	int min = findMin(root);
	cout << min;

	cout << endl;
	
	int max = findMax(root);
	cout << max;
}