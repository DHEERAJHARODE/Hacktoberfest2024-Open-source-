// C++ program to add one to a linked list

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
           data = x;
        next = nullptr;
    }
};

// Recursively add 1 from end to beginning and return
// carry after all nodes are processed.
int addWithCarry(Node *head) {
  
    // If linked list is empty, return carry
    if (head == nullptr) {
        return 1;
    }

    // Add carry returned by the next node call
    int res = head->data + addWithCarry(head->next);

    // Update data and return new carry
    head->data = res % 10;
    return res / 10;
}

Node *addOne(Node *head) {
  
    // Add 1 to linked list from end to beginning
    int carry = addWithCarry(head);

    // If there is carry after updating all nodes,
    // then we need to add a new node to the linked list
    if (carry) {
        Node *newNode = new Node(carry);
        newNode->next = head;

          // New node becomes head now
          return newNode; 
    }

    return head;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
      // Create a hard-coded linked list:
    // 1 -> 9 -> 9 -> 9
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
  
    head = addOne(head);

    printList(head);

    return 0;
}
