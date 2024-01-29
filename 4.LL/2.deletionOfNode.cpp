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

// Creating Linked List from array
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

// Traverse Linked List
void traverseLL(Node* head){
	Node* temp=head;
	while(temp){
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << endl;
}

// 1. Deleting node from head 
void deleteHead(Node** refToHead,Node* head){
	Node* temp = head;
	*refToHead = temp->next;
	delete temp;
}

// 2. Deleting node from tail
void deleteTail(Node* head){
	if(head == NULL || head->next == NULL)free(head);
	Node* temp = head;
	while(temp->next->next){
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}

// 3. Delete kth node
void deleteNode(Node* head,Node** refToHead,int i){
	// EC1 : LL is empty
	if(i<0 || head == nullptr) return;
	Node* toDel;
	Node* temp = head;

	// EC2 : delete first element
	if(i==0){
		*refToHead = temp->next;
		return;
	}
	while(i>1){
		i--;
		temp=temp->next;
		// EC3 :
		if(temp->next == nullptr) return;
	}

	toDel = temp->next;
	temp->next = toDel->next;
	delete toDel;
}

// 4. Delete by value
void deleteValue(Node* head,Node** refToHead , int target){
	// EC1 : LL is empty
	if(head == nullptr) return;
	Node* toDel;
	Node* temp = head;

	// EC2 : delete first element
	if(head->data == target){
		*refToHead = head->next;
		return;
	}
	while(temp->next->data != target){
		temp=temp->next;
		// EC3 : 
		if(temp->next == nullptr) return;
	}

	toDel = temp->next;
	temp->next = toDel->next;
	delete toDel;	
}

int main(){
	vector<int> arr = {12 , 34 , 56 , 78 , 14 , 19 , 67 , 89};
	// Convert the array to linked list
	Node* head = arr2LL(arr);
	// Traverse the linked list and print values
	traverseLL(head);


	// 1. Delete node from head
	Node** refToHead = &head;
	deleteHead(refToHead,head);
	traverseLL(head);

	// 2. Delete node from tail
	deleteTail(head);
	traverseLL(head);

	// 3. Delete kth node
	int i = 4; 
	deleteNode(head,refToHead,i);
	traverseLL(head);
	
	// 4. Delete value
	int target = -1;
	deleteValue(head,refToHead,target);
	traverseLL(head);
}