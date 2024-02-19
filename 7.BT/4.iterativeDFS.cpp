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

// 1. inOrder iterative traversal 
vector<int> inOrder(Node* root){
	vector<int> ans;
	stack<Node*> s;

	Node* node = root;

	while(true){
		if(node){
			s.push(node);
			node=node->left;
		}else {
			if(s.empty()) break;
			node = s.top();
			s.pop();
			ans.push_back(node->data);
			node=node->right;
		}
	}

	return ans;
}

// 2.preOrder Itereative traversal
vector<int> preOrder(Node* node){
	vector<int> ans;
	if(!node) return ans;
	stack<Node*> stck;

	stck.push(node);

	while(!stck.empty()){
		Node* temp = stck.top();
		ans.push_back(temp->data);
		stck.pop();
		if(temp->right)stck.push(temp->right);
		if(temp->left)stck.push(temp->left);
	}

	return ans;
}


int main(){
	// creating BT
	Node* root = createBT();

	// 1.inOrder
	vector<int> ans1 = inOrder(root);
	for(auto it:ans1) cout << it << " ";
	cout << endl;

	// 2.preOrder
	vector<int> ans2 = preOrder(root);
	for(auto it : ans2) cout << it << " ";

		
}