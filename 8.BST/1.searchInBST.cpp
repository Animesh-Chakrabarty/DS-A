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

bool searchRecursive(Node* node, int target){
	if(!node)return 0;
	if(node->data == target) return 1;

	else if (node->data > target){
		return searchRecursive(node->left,target);
	}
	else if(node->data < target){
		return searchRecursive(node->right,target);
	}

	return 0;
}

bool serachIterative(Node* node, int target){
	bool ans;
	while(node && node->data != target){
		node = node->data > target ? node->left : node->right;
	}

	if(node && node->data==target)ans = 1;
	else ans = 0;
	return 1;
}

int main(){
	Node* root = createBST();

	// search for value - recursive
	int target = 6;
	bool ans = searchRecursive(root,target);
	cout << ans;

	cout << endl;

	// search for value - iterative
	bool ans2 = serachIterative(root,target);
	cout << ans;
}