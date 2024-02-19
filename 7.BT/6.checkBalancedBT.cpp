#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

public:
	Node(int value){
		data=value;
		left=right=nullptr;
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

	return root;
}




// return -1 -> not height balanced 
// return any other value -> height balanced
int dfsHeight(Node* node){
	if(!node) return 0;

	int lh = dfsHeight(node->left);
	if(lh == -1) return -1;
	int rh = dfsHeight(node->right);
	if(rh == -1) return -1;

	if(abs(lh-rh) > 1)return -1;

	return 1 + max(lh,rh);
}


bool checkBalanced(Node* root){
	int ans = dfsHeight(root);
	return ans != -1;
}

int main(){
	Node* root = createBT();
	bool ans = checkBalanced(root);
	cout << ans;
}