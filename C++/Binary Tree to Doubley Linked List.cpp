// A C++ program for in-place conversion of Binary Tree to
// DLL
#include <iostream>
using namespace std;

/* A binary tree node has data, and left and right pointers
*/
struct node {
	int data;
	node* left;
	node* right;
};

// A simple recursive function to convert a given Binary
// tree to Doubly Linked List root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked
// list
void BinaryTree2DoubleLinkedList(node* root, node** head)
{
	// Base case
	if (root == NULL)
		return;

	// Initialize previously visited node as NULL. This is
	// static so that the same value is accessible in all
	// recursive calls
	static node* prev = NULL;

	// Recursively convert left subtree
	BinaryTree2DoubleLinkedList(root->left, head);

	// Now convert this node
	if (prev == NULL)
		*head = root;
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	// Finally convert right subtree
	BinaryTree2DoubleLinkedList(root->right, head);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->right;
	}
}

// Driver Code
int main()
{
	// Let us create the tree shown in above diagram
	node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL
	node* head = NULL;
	BinaryTree2DoubleLinkedList(root, &head);

	// Print the converted list
	printList(head);

	return 0;
}
