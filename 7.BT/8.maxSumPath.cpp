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
	Node* root = new Node(-10);

	root->left = new Node(9);
	root->right = new Node(20);

	root->right->left = new Node(15);
	root->right->right = new Node(7);

	return root;
}

int nodeWiseMaxPathSum(Node* node , int& maxSum){
	if(!node)return 0;

	int lMaxSum = max(0,nodeWiseMaxPathSum(node->left,maxSum));
	int rMaxSum = max(0,nodeWiseMaxPathSum(node->right,maxSum));

	maxSum = max(maxSum, node->data+ lMaxSum+ rMaxSum);

	return (node->data+ max(lMaxSum,rMaxSum));
}

int maxPathSum(Node* root){
	int maxSum = -1;
	nodeWiseMaxPathSum(root , maxSum);
	return maxSum;
}

int main(){
	Node* root = createBT();

	int ans = maxPathSum(root);
	cout << ans;
}