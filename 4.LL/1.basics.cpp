#include<bits/stdc++.h>
using namespace std;

// Defining Node 
class Node{

// Node data Points 
public:
	int data;
	Node* next;

// Node constructor 
public:
	Node(int data1 , Node* next1){
		data = data1;
		next=next1;
	}

public:
	Node(int data1){
		data=data1;
		next=nullptr;
	}
};


// 1. Convert array to Linked List
Node* arr2LL(vector<int> &arr){
	Node* head = new Node(arr[0]);
	Node* mover = head;
	for (int i = 1; i < arr.size(); ++i){
		Node* temp = new Node(arr[i]);
		mover->next = temp;
		mover=temp;
	}
	return head;
}

// 2. Traverse LL
void traverseLL(Node* head){
	Node* temp=head;
	while(temp){
		cout << temp->data << " ";
		temp=temp->next;
	}
}

// 3. Length of the linked list
int findLen(Node* head){
	int count = 0;
	Node* temp = head;

	while(temp){
		count++;
		temp=temp->next;
	}
	return count;
}

// 4. Search Element
bool searchElement(Node* head,int target){
	Node* temp = head;
	while(temp){
		if(temp->data == target) return true;
		else temp=temp->next;
	}
	return false;
}

int main(){
	// Convert this array to linked list
	vector<int> arr = {1 , 34 , 56 , 78 , 14};
	Node* head = arr2LL(arr);
	// Traverse the linked list and print values
	traverseLL(head);
	cout << endl;
	// find length of the linked list
	int len = findLen(head);
	cout << "length : " << len << endl;
	// Search for an element in linked list
	int searchFor = 1;
	bool doesExist =  searchElement(head,searchFor);
	cout << doesExist;
}

// TC -> O(N)