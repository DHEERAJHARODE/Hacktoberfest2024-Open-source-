#include <bits/stdc++.h> 
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(K==0) return head;
    LinkedListNode<int> *slow= head, *fast=head;
    while(K--)
        fast=fast->next;
    if(fast==NULL) return head->next; //return empty list

    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}