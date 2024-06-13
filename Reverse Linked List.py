class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev=None
        curr=head
        while(curr!=None):
            temp=curr.next
            curr.next=prev
            prev=curr
            curr=temp
        return prev
