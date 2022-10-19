#include <bits/stdc++.h> 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL) return head;
    // this reverses all the nodes after the head and point back to the 2nd node
    LinkedListNode<int> *newHead = reverseLinkedList(head->next);
    // making 2nd node point to the head
    head->next->next=head;
    head->next=NULL; //thus head becomes the tail
    return newHead; // newHead would be the last node
}