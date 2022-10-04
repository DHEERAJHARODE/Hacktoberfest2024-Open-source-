ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        ListNode* fast = start,*slow = start;
        start->next = head;
        
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
