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

// Reverse DLL
void reverseDLL(Node* head , Node** refToHead){
	Node* temp;
	Node* pointer = head;

	while(pointer){
		temp = pointer->prev;
		pointer->prev=pointer->next;
		pointer->next=temp;
		if(!pointer->prev){
			*refToHead=pointer;
		}
		pointer=pointer->prev;
	}
}


int main(){
	vector<int> arr = {1,56,23,78,90,12,34};

	Node* head = arrToDll(arr);
	traverseDLL(head);

	Node** refToHead = &head;
	reverseDLL(head,refToHead);
	traverseDLL(head);
}