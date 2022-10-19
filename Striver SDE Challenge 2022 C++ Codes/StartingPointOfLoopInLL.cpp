#include <bits/stdc++.h> 
Node *firstNode(Node *head)
{
	int f=0;//flag to check if h and t meet in first while loop
    if(head==NULL || head->next==NULL) return NULL;
    Node *h=head;
    Node *t=head;
    while(h!=NULL && h->next!=NULL){//also checks if no cycle present
        h=h->next->next;
        t=t->next;
        if(h==t) {f=1;break;}
    }
    if(f==0) return NULL;//no cycle, h=NULL
    if(h==head) return h;//Example 2
    else{
        t=head;//h is at first pt of intersection but t starts from start
        while(h!=t){
            h=h->next;
            t=t->next;
        }
        return h;
    }
}