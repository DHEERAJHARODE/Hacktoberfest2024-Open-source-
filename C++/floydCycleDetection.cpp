#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

// initialize a new head for the linked list
Node* head = NULL;
class Linkedlist {
public:
	// insert new value at the start
	void insert(int value)
	{
		Node* newNode = new Node(value);
		if (head == NULL)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	// detect if there is a loop
	// in the linked list
	bool detectLoop()
	{
		Node *slowPointer = head,
			*fastPointer = head;

		while (slowPointer != NULL
			&& fastPointer != NULL
			&& fastPointer->next != NULL) {
			slowPointer = slowPointer->next;
			fastPointer = fastPointer->next->next;
			if (slowPointer == fastPointer)
				return 1;
		}

		return 0;
	}
};

int main()
{
	Linkedlist l1;
	// inserting new values
	l1.insert(10);
	l1.insert(20);
	l1.insert(30);
	l1.insert(40);
	l1.insert(50);

	// adding a loop for the sake
	// of this example
	Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = head;

	// loop added;

	if (l1.detectLoop())
		cout << "Loop exists in the"
			<< " Linked List" << endl;
	else
		cout << "Loop does not exists "
			<< "in the Linked List" << endl;

	return 0;
}
