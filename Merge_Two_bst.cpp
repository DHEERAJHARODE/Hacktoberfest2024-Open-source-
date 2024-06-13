#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node* left;
	node* right;
};

// A utility function to merge two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n);

// A helper function that stores inorder
// traversal of a tree in inorder array
void storeInorder(node* node, int inorder[],
							int *index_ptr);
node* sortedArrayToBST(int arr[], int start, int end);
node* mergeTrees(node *root1, node *root2, int m, int n)
{
	// Store inorder traversal of
	// first tree in an array arr1[]
	int *arr1 = new int[m];
	int i = 0;
	storeInorder(root1, arr1, &i);

	// Store inorder traversal of second
	// tree in another array arr2[]
	int *arr2 = new int[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	// Merge the two sorted array into one
	int *mergedArr = merge(arr1, arr2, m, n);

	// Construct a tree from the merged
	// array and return root of the tree
	return sortedArrayToBST (mergedArr, 0, m + n - 1);
}

/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

// A utility function to print inorder
// traversal of a given binary tree
void printInorder(node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

// A utility function to merge
// two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n)
{
	// mergedArr[] is going to contain result
	int *mergedArr = new int[m + n];
	int i = 0, j = 0, k = 0;

	// Traverse through both arrays
	while (i < m && j < n)
	{
		// Pick the smaller element and put it in mergedArr
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	// If there are more elements in first array
	while (i < m)
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}

	// If there are more elements in second array
	while (j < n)
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}

// A helper function that stores inorder
// traversal of a tree rooted with node
void storeInorder(node* node, int inorder[], int *index_ptr)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	storeInorder(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	/* now recur on right child */
	storeInorder(node->right, inorder, index_ptr);
}

/* A function that constructs Balanced
// Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
node* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	node *root = newNode(arr[mid]);

	/* Recursively construct the left subtree and make it
	left child of root */
	root->left = sortedArrayToBST(arr, start, mid-1);

	/* Recursively construct the right subtree and make it
	right child of root */
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}

/* Driver code*/
int main()
{
	node *root1 = newNode(100);
	root1->left	 = newNode(50);
	root1->right = newNode(300);
	root1->left->left = newNode(20);
	root1->left->right = newNode(70);

	/* Create following tree as second balanced BST
			80
		/ \
		40 120
	*/
	node *root2 = newNode(80);
	root2->left	 = newNode(40);
	root2->right = newNode(120);

	node *mergedTree = mergeTrees(root1, root2, 5, 3);

	cout << "Following is Inorder traversal of the merged tree \n";
	printInorder(mergedTree);

	return 0;
}
