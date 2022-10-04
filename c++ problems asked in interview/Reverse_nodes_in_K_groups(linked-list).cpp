// Q. 
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is 
// not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

// Solution 1:(Recursion)

// Approach:

// 1) The first step is to check whether the Head is NULL or Not, if its NULL then we can directly return NULL,
// 2) If the Head is not NULL, then we need to check the length of Linked List starting from current Head.
// 3) If it is not a multiple of K(Less than K) , then there is no need to reverse it and hence we can directly return head,
// 4) Else if its a multiple of K, then we have to reverse the K elements starting from current Head,
// 5) We will follow the same steps for the rest of the elements Recursively.

// C++:

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
        ListNode *KSizeChecker = head;
        for(int i=0;i<k;i++)
        {
            if(KSizeChecker==NULL)
                return head;
            KSizeChecker = KSizeChecker->next;
        }
        int cnt=0;
        ListNode *cur=head,*prev=NULL,*next=NULL;
        while(cur and cnt<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            cnt++;
        }
        if(next)
            head->next=reverseKGroup(next,k);
        return prev;
    }
};

// Solution 2:(Iterative):
// Approach:

// 1) We first try to find out the length of linked list,
// Let it be "Len"
// 2) Now we try to find out , how many groups of size "K" are there to reverse,
// this can be easily done using the formula --- "Len/K"
// 3) Hence we have Len/K groups to reverse,
// 4) To easily find out the new Linked List's Head(After reversal), we will make a dummyNode just before the head,
// and at last for new Head we can directly return dummyNode->next,
// 5) The reversal of linked list is very easy ,
// we just need to keep track of remaining Nodes and the new head for reversed linked list.


// C++:

class Solution {
    int getLengthOfLinkedList(ListNode *head)
    {
        ListNode *ptr = head;
        int cnt=0;
        while(ptr)
        {
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
    
        int len = getLengthOfLinkedList(head);
        if(len<k)
            return head;
        
        int numberOfGroupsToReverse = len/k;
        
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *start = dummyNode;

        ListNode *pre,*remaining,*next;
        for(int i=0;i<numberOfGroupsToReverse;i++)
        {
            pre = NULL;
            remaining = head;
            for(int j=0;j<k;j++)
            {
                next = head->next;
                head->next = pre;
                pre=head;
                head=next;
            }
            start->next = pre;
            remaining->next = head;
            start = remaining;
        }
        
        return dummyNode->next;
    }
};