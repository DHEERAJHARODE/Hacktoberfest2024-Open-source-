Node* copyRandomList(Node* head) {
        Node *fast=head;
        Node *t=head;
        
        // adding copy nodes after each original node
        while(t){
            fast=t->next;
            Node *temp = new Node(t->val);
            t->next=temp;
            temp->next=fast;
            t=fast;
        }
        t=head;
        // setting the random pointer of copy nodes
        
        
        while(t){
            if(t->random) t->next->random=t->random->next; //next of every original node is a copy node, so here we are setting random of copy ones
            t=t->next->next;
        }
        
        
        // separating original and copy nodes
        t=head;
        fast=head;
        Node *dummy = new Node(0);//to store head of copy list
        Node *copy=dummy;//to traverse and build copy list
        while(t){
            fast=t->next->next;
            copy->next=t->next;
            t->next=fast;
            copy=copy->next;
            t=t->next;
        }
        
        return dummy->next; //as the first node was 0
    }