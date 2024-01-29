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

void traverseDLL(Node* head){
	Node* pointer = head;
	while(pointer){
		cout << pointer->data << " ";
		pointer = pointer->next;
	}
	cout << endl;
}

// 1. Insert at head
void insertHead(Node* head,Node** refToHead,int value){
	Node* temp = new Node(value);
	temp->next = head;
	*refToHead = temp;
}	

// 2. Insert at tail
void insertAtTail(Node* head, int value){
	Node* temp = new Node(value);
	Node* pointer = head;

	while(pointer->next){
		pointer = pointer->next;
	}

	pointer->next = temp;
	temp->prev = pointer;
}

int main(){
	vector<int> arr = {1,56,23,78,90,12,34};

	Node* head = arrToDll(arr);
	traverseDLL(head);

	// 1. Insert at head
	Node** refToHead = &head;
	int value = 200;
	insertHead(head,refToHead,value);
	traverseDLL(head);

	// 2. Insert at tail
	insertAtTail(head,value);
	traverseDLL(head);
}