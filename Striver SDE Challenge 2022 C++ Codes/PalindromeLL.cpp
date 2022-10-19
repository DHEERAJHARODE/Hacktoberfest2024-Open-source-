bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow is on mid, reverse this part of list
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode* dummy = head;
        while(slow!=NULL) {
            if(dummy->val != slow->val) return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* ptr) {
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        while(ptr!=NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
        return pre;
    }