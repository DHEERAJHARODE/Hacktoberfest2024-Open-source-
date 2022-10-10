class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head -> next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL) {
            fast = fast -> next;
            if(fast != NULL) fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};