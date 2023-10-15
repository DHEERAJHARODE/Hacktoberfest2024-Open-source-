// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in 
// reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a 
// linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode* new_node = NULL;
        while(head != NULL){
            ListNode* forward = head->next;
            head->next = new_node;
            new_node = head;
            head = forward;
        }
        return new_node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (l1!=NULL || l2!=NULL|| carry){
            int sum = 0;
            if (l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum += carry;
            carry=sum/10;
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};