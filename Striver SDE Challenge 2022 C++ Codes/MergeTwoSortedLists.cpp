#include <bits/stdc++.h> 
Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
    Node<int>* l1=list1;
    Node<int>* l2=list2;
    Node<int>* hptr=l1;//assuming that l1 has smaller head than l2
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    //choosing the right head node
    if(l2->data<l1->data){
        hptr=l2;
        l2=l2->next;//now l2 starts from its 2nd val
    }
    else l1=l1->next;
    //initialise head ptr of new list
    Node<int>* curr=hptr; //a new ptr for traversing and creating the new merged LL
    while(l1 && l2){
        if(l1->data < l2->data){
            curr->next = l1;
            l1=l1->next;
        }
        else{
            curr->next = l2;
            l2=l2->next;
        }
        curr=curr->next; //moving curr to next node to attach the next node to the currently attached one or else in next iteration the currently attached node would be replaced by the next one
    }
    //while ends; now l1 and l2 nodes point to the remaining items of each
    if(l1) curr->next=l1;
    else curr->next=l2;
    return hptr;
}
