class compare {
    public:
    bool operator() (ListNode *a, ListNode *b) {
        return a -> val > b -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector<ListNode*>, compare> pq;
        ListNode * dummy = new ListNode(-1);
        ListNode * tail = dummy;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL)
            pq.push(lists[i]);
        }
        while(!pq.empty()) {
            ListNode * temp = pq.top();
            tail -> next = temp;
            tail = temp;
            pq.pop();
            if(temp -> next != NULL) pq.push(temp -> next);
        }

        return dummy -> next;
    }
};