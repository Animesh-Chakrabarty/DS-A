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

int findCeil(Node* node, int value){
	int ans = -1;
	while(node){
	 	if(node->data == value){
	 		ans = node->data;
	 		break;
	 	} 
	 	else if(node->data > value){
	 		ans = node->data;
	 		node = node->left;
	 		continue;
	 	} 
	 	else {
	 		node = node->right;
	 		continue;
	 	}
				
	}

	return ans;
}

int main(){
	Node* root = createBST();

	int value = 11;
	int ceil = findCeil(root, value);
	cout << ceil;
}