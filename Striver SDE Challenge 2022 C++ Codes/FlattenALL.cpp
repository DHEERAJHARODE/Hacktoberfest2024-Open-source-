#include <bits/stdc++.h> 
Node* merge2LL(Node* a, Node* b){
    Node *temp = new Node(0);
    Node *res=temp;
    while(a && b){
        if(a->data < b->data){
            temp->child=a;
            temp=temp->child;
            a=a->child;
        }
        else{
            temp->child=b;
            temp=temp->child;
            b=b->child;
        }
    }
    if(a) temp->child=a;
    else temp->child=b;
    return res->child;
}

Node *flattenLinkedList(Node *head) 
{
	if(!head || !head->next) return head;
    head->next = flattenLinkedList(head->next);
    head = merge2LL(head,head->next);
    return head;
}