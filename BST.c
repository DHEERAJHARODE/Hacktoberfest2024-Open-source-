#include <stdio.h>
#include <malloc.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Case 8
int isBSTUtil(struct Node *root, struct Node *prev)
{
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBSTUtil(root->right, prev);
    }
    return 1;
}
int isBST(struct Node *root)
{
    struct Node *prev = NULL;
    return isBSTUtil(root, prev);
}

// Case 1
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        printf("Duplicate key cannot be inserted");
    return root;
}

// Case 2
struct Node *minValueNode(struct Node *root) // Finding the smallest in greatest means finding the smallest from right subtree
{
    struct Node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Item Not found");
        return NULL;
    }
    if (key < root->data)
        root->left = deleteNode(root->left, key); // remeber this
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp; // returning temp to rcursive function
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValueNode(root->right);
    }
    return root;
}
// Case 4
struct Node *searchRecur(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data > key)
        searchRecur(root->left, key);
    else
        searchRecur(root->right, key);
}

// Case 3
struct Node *searchIter(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Case 5
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Case 6
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Case 7
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    int choices;
    while (1 == 1)
    {
        printf("\n\n\t1 for insertion\t\t\t\t2 for deletion\t\t\t\t\t\t3 for iterative searching\n\t4 for recursive searching \t\t");
        printf("5 for preorder transversal \t\t\t\t6 for postorder transversal \n\t7 for inorder transversal \t\t");
        printf("8 to check if this is binary search tree or not\t\t9 for exiting the system");
        printf("\nEnter your choice:");
        scanf("%d", &choices);
        int key;
        switch (choices)
        {
        case 1:
            printf("\n\nEnter the key to insert:");
            scanf("%d", &key);
            if (root == NULL)
                root = insert(root, key);
            else
                insert(root, key);
            break;
        case 2:
            if (root == NULL)
                printf("There is no item in the tree to delete");
            else
            {
                printf("\n\nEnter the key to delete:");
                scanf("%d", &key);
                deleteNode(root, key);
            }
            break;
        case 3:
            printf("Enter the elemnt to search by iterative search:");
            scanf("%d", &key);
            struct Node *n = searchIter(root, key);
            if (n == NULL)
            {
                printf("\nKey Not found");
            }
            else
                printf("\nThe %d is present in the tree", n->data);
            free(n);
            break;
        case 4:
            printf("Enter the elemnt to search by recursive search:");
            scanf("%d", &key);
            struct Node *k = searchRecur(root, key);
            if (n == NULL)
                printf("\nKey Not found");
            else
                printf("\nThe %d is present in the tree", k->data);
            free(k);
            break;
        case 5:
            printf("\nShowing preorder transversal:\n\n\t\t");
            preorder(root);
            break;
        case 6:
            printf("\nShowing postorder transversal:\n\n\t\t");
            postorder(root);
            break;
        case 7:
            printf("\nShowing inorder transversal:\n\n\t\t");
            inorder(root);
            break;
        case 8:
            if (isBST(root))
            {
                printf("Given tree is a Binary Search Tree");
                break;
            }
            else
            {
                printf("Given tree is not a Binary Search Tree");
                break;
            }
        case 9:
            printf("Thank you for using the system Hope.I will see you again");
            exit(0);
        default:
            printf("\nInavlid Input!!Please enter a valid key");
            break;
        }
    }
}
