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

vector<int> BFS(Node* node){
	vector<int> ans;
	if(!node) return ans;
	queue<Node*> q;

	// pushing the root to the queue
	q.push(node);

	while(!q.empty()){
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			if(q.front()->left)q.push(q.front()->left);
			if(q.front()->right)q.push(q.front()->right);
			ans.push_back(q.front()->data);
			q.pop();
		}
	}
	return ans;
}

int main(){
	// creating BT
	Node* root = createBT()	;
	// 1.BFS
	vector<int> ans = BFS(root);
	for(auto it : ans)cout << it << " ";
}