#include <bits/stdc++.h> 
bool detectCycle(Node *head)
{
	if(head==NULL || head->next==NULL) return false;
        Node *h=head;
        Node *t=head;
        while(h!=NULL && h->next!=NULL){
            h=h->next->next;
            t=t->next;
            if(h==t) return true;
        }
        return false;
}