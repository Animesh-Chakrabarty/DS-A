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
	Node* root =  new Node(5);

	root->left = new Node(2);
	root->right = new Node(1);

	root->left->right = new Node(10);

	root->right->left = new Node(3);
	root->right->right = new Node(4);

	root->right->left->left = new Node(8);
	root->right->left->right = new Node(11);

	return root;
}

// approach 1 - using BFS 
int heightOfBT1(Node* node){
	int level = 0;
	if(!node) return level;
	queue<Node*> q;

	// pushing the root to the queue
	q.push(node);


	while(!q.empty()){
		level++;
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			if(q.front()->left)q.push(q.front()->left);
			if(q.front()->right)q.push(q.front()->right);
			q.pop();
		}
	}
	return level;
}

// approach 2 - recursive
int heightOfBT2(Node* node){
	if(!node) return 0;

	int lh = heightOfBT2(node->left);
	int rh = heightOfBT2(node->right);

	return 1+max(lh,rh);
}

int main(){
	// create BT
	Node* root = createBT();

	// approach 1 - using BFS 
	// No of levels in BFS = height of the tree
	// TC - O(N)
	// SC - O(N) - using queue
	int height1 = heightOfBT1(root);
	cout << height1 << endl;


	// approach 2 - using recursive solution
	// height of BT = 1 + max(height of left subtree , height of right subtree)
	// TC - O(N)
	// SC - 
	int height2 = heightOfBT2(root);
	cout << height2 << endl;


}