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

// 1. Insert at Head
void insertAtHead(Node* head,Node** refToHead,int value){
	Node* temp = new Node(value);
	temp->next = head;
	*refToHead = temp;
}

// 2. Insert at Tail
void insertAtTail(Node* head,int value){
	Node* temp = new Node(value);
	Node* tracker = head;

	while(tracker->next != nullptr){
		tracker = tracker->next;
	}
	tracker->next = temp;
}

// 3. Insert at given Index
void insertAtIndex(Node* head,Node** refToHead ,int value,int i){
	if(i<0) return;
	Node* temp = new Node(value);
	Node* tracker = head;
	// EC : 
	if(i == 0){
		temp->next = head;
		*refToHead = temp;
		return;
	}
	// EC  : LL is empty
	if(head == nullptr){
		*refToHead = temp;
		return;
	}

	while(i > 1){
		// EC  : index > length
		if(tracker->next == nullptr) return;

		i--;
		tracker = tracker->next;
	}

	temp->next = tracker->next;
	tracker->next = temp;
}

// 4. Insert element before value
void insertBeforeValue(Node* head, Node** refToHead, int value , int valueBefore){
	Node* temp = new Node(value);
	Node* tracker = head;

	// EC : insert At head
	if(head->data == valueBefore){
		temp->next = head;
		*refToHead = temp;
		return;
	}
	
	// EC  : LL is empty
	if(head == nullptr){
		*refToHead = temp;
		return;
	}

	while(tracker->next != nullptr && tracker->next->data != valueBefore){
		tracker = tracker->next;
	}

	// EC  : 
	if(tracker->next == nullptr) return;

	temp->next = tracker->next;
	tracker->next = temp;
}

int main(){
	vector<int> arr = {12 , 34 , 56 , 89};
	// Convert the array to linked list
	Node* head = arr2LL(arr);
	// Traverse the linked list and print values
	traverseLL(head);

	// 1. Insert at Head
	int valueToInsertAtHead = 90;
	Node** refToHead = &head;
	insertAtHead(head,refToHead,valueToInsertAtHead);
	traverseLL(head);

	// 2. Insert at Tail
	int valueToInsertAtTail = 3;
	insertAtTail(head,valueToInsertAtTail);
	traverseLL(head);

	// 3. Insert at a Given index
	int valueToInsertAtIndex = 800;
	int i = 4;
	insertAtIndex(head,refToHead,valueToInsertAtIndex,i);
	traverseLL(head);

	// 4. Insert element before value
	int valueToInsert = -1;
	int valueToInsertBefore = 56;
	insertBeforeValue(head,refToHead,valueToInsert,valueToInsertBefore);
	traverseLL(head);
}