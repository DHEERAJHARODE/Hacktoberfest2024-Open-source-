#include <bits/stdc++.h> 
Node *rotate(Node *head, int k) {
     if(!head || !head->next || k==0) return head;
    Node *last=head,*prev=head;
    int l=0;
    while(last){
        l++;
        last=last->next;
    }
    if(k%l==0) return head;
    // cout<<l<<endl;

    int i=l-(k%l);
    last=head;
    while(i){
        prev=last;
        last=last->next;
        i--;
    }
    // cout<<prev->val<<" "<<last->val;
    while(last->next){
        last=last->next;
    }
    last->next=head;
    head=prev->next;
    prev->next=NULL;
    return head;
}