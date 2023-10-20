// Aim of the program: Huffman coding assigns variable length codewords to fixed length input
// characters based on their frequencies or probabilities of occurrence. Given a set of characters
// along with their frequency of occurrences, write a c program to construct a Huffman tree.
// Note#
//  Declare a structure SYMBOL having members alphabet and frequency. Create a Min-
// Priority Queue, keyed on frequency attributes.
//  Create an array of structures where size=number of alphabets.
// Input:
// Enter the number of distinct alphabets: 6
// Enter the alphabets: a b c d e f
// Enter its frequencies: 45 13 12 16 9 5
// Output:
// In-order traversal of the tree (Huffman): a c b f e d


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a symbol
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Define a structure for a node in the Huffman tree
struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};

// Define a structure for the min-heap
struct MinHeap {
    int size;
    struct Node** array;
};

// Function to create a new node with the given symbol and frequency
struct Node* createNode(struct SYMBOL symbol) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a min-heap node with the given array of nodes
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return minHeap;
}

// Function to swap two nodes in the min-heap
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->symbol.frequency < minHeap->array[smallest]->symbol.frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->symbol.frequency < minHeap->array[smallest]->symbol.frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNodes(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the size of the min-heap is 1 (used to build the Huffman tree)
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum from the min-heap
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a node into the min-heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->symbol.frequency < minHeap->array[(i - 1) / 2]->symbol.frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct Node* left, * right, * top;
    struct MinHeap* minHeap = createMinHeap(n);

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(symbols[i]);
        insertMinHeap(minHeap, newNode);
    }

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        struct SYMBOL tempSymbol = { '*', left->symbol.frequency + right->symbol.frequency };
        top = createNode(tempSymbol);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to perform in-order traversal of the Huffman tree
void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    struct Node* root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
