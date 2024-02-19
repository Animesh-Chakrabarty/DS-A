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

Node* createBT1(){
	Node* root = new Node(-10);

	root->left = new Node(9);
	root->right = new Node(20);

	root->right->left = new Node(15);
	root->right->right = new Node(7);

	return root;
}

Node* createBT2(){
	Node* root = new Node(-10);

	root->left = new Node(9);
	root->right = new Node(20);

	root->right->left = new Node(15);
	root->right->right = new Node(7);
	
	return root;
}

bool checkIdentical(Node* node1, Node* node2){
	if(!node1 && !node2) return 1;
	else if(!node1 && node2) return 0;
	else if(node1 && !node2) return 0;

	// If the values of root are not same then there is not point of checking any further so return 0
	if(node1->data != node2->data) return 0;

	bool checkL = checkIdentical(node1->left,node2->left);
	if(checkL){
		bool checkR = checkIdentical(node1->right,node2->right);
		if(!checkR) return 0;

	}else return 0;

	return 1;
}

int main(){
	Node* root1 = createBT1();
	Node* root2 = createBT2();

	bool ans = checkIdentical(root1 , root2);
	cout << ans;
}