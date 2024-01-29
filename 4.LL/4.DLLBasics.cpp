#include<bits/stdc++.h>
using namespace std;

class Node{
public:	
	int data;
	Node* prev;
	Node* next;

public:
	Node(int data1,Node* prev1,Node* next1){
		data=data1;
		prev=prev1;
		next=next1;
	}

public:
	Node(int data1){
		data=data1;
		prev=next=nullptr;
	}
};

// 1. Convert array to DLL
Node* arrToDll(vector<int> &arr){
	Node* head = new Node(arr[0]);
	Node* pointer = head;
	for (int i = 1; i < arr.size(); ++i)
	{
		Node* temp = new Node(arr[i]);
		pointer->next = temp;
		temp->prev = pointer;
		pointer=pointer->next;
	}
	return head;
}

// 2. Traverse DLL
void traverseDLL(Node* head){
	Node* pointer = head;
	while(pointer){
		cout << pointer->data << " ";
		pointer = pointer->next;
	}
}

int main(){
	vector<int> arr = {1,56,23,78};

	// 1. Convert the Array to DLL
	Node* head = arrToDll(arr);
	// 2. Traverse DLL
	traverseDLL(head);
}