Node* connect(Node* root) {
        if(root==NULL)
            return root;
        //cur traverses thru each node in a level
        //nxt stands at the beginning of each level belwo the cur
        Node* cur=root;
        Node* nxt=root->left;
        root->next=NULL;
        while(cur && nxt){
            cur->left->next = cur->right;
            if(cur->next) 
                cur->right->next=cur->next->left;
            //move cur to the next node in the same level
            cur=cur->next;
            if(!cur){
                //move cur to the next level
                cur=nxt;
                //move nex to the next level
                nxt=nxt->left;
            }
        }
        return root;
    }