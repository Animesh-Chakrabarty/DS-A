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

// creating BT
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

// 1.inOrder traversal
void inOrder(Node* node){
	if(!node)return;

	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

// 2.preOrder traversal
void preOrder(Node* node){
	if(!node) return;

	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

// 3.postOrder traversal
void postOrder(Node* node){
	if(!node) return;

	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << " ";
}

int main(){
	// creating BT
	Node* root = createBT();

	// 1.inOrder traversal
	inOrder(root);
	cout << endl;

	// 2.preOrder traversal
	preOrder(root);
	cout << endl;
	
	// 3.postOrder traversal
	postOrder(root);
}