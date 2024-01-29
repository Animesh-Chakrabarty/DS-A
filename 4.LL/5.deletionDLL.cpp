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

// 1. Delete head
void deleteHead(Node* head,Node** refToHead){
	Node* temp = head;
	*refToHead = head->next;
	head->prev = nullptr;
	delete temp;
}

// 2. Delete Tail 
void deleteTail(Node* head){
	Node* pointer = head;
	Node* temp;

	while(pointer->next){
		pointer = pointer->next;
	}

	temp = pointer;
	pointer->prev->next = nullptr;
	delete temp;
}

// 3. Delete node from kth index
void deleteIndex(Node* head, Node** refToHead, int k){
	// EC1 : index less than 0
	if(k<0) return;
	Node* pointer = head;
	Node* temp;

	// EC2 : delete first element
	if(k == 0){
		temp = head;
		*refToHead = head->next;
		head->prev = nullptr;
		delete temp;
		return;
	}
	while(k && pointer){
		pointer = pointer->next;
		k--;
	}

	// EC 3 : k > arr.size()+1
	if(!pointer) return;

	temp = pointer;
	pointer->prev->next = pointer->next;
	if(pointer->next){
		pointer->next->prev = pointer->prev;
	}
	delete temp;
}

// 4. Delete value
void deleteValue(Node* head, Node** refToHead, int value){
	Node* pointer = head;
	Node* temp;

	// EC1 : delete first element
	if(value == head->data){
		temp = head;
		*refToHead = head->next;
		head->prev = nullptr;
		delete temp;
		return;
	}
	while(pointer && pointer->data != value){
		pointer = pointer->next;
	}

	// EC 2 : value doesn't exist 
	if(!pointer) return;

	temp = pointer;
	pointer->prev->next = pointer->next;
	if(pointer->next){
		pointer->next->prev = pointer->prev;
	}
	delete temp;
}

int main(){
	vector<int> arr = {1,56,23,78,90,12,34};

	Node* head = arrToDll(arr);
	traverseDLL(head);

	// 1. Delete Head
	Node** refToHead = &head;
	deleteHead(head,refToHead);
	traverseDLL(head);

	// 2. Delete Tail
	deleteTail(head);
	traverseDLL(head);

	// 3. Delte node from kth index
	int k = 70;
	deleteIndex(head,refToHead, k);
	traverseDLL(head);

	// 4. Delete element of given value
	int value = 121;
	deleteValue(head,refToHead,value);
	traverseDLL(head);
}