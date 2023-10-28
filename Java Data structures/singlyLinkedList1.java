public class singlyLinkedList1
{
    private ListNode head;
    private static class ListNode
    {
        private int data;
        private ListNode next;
        public ListNode (int data)
        {
            this.data=data;
            this.next=null;
        }
    }
    public void display()
    {
        ListNode current=head;
        while(current!=null)
        {
            System.out.print(current.data+"-->");
            current=current.next;
        }
        System.out.println("null");
    }
    public static void main (String args[])
    {
        singlyLinkedList1 sll = new singlyLinkedList1();
        sll.head =new ListNode(10);
        ListNode second =new ListNode(1);
        ListNode third=new ListNode(8);
        ListNode fourth=new ListNode(11);
        // NOW WE CONNECT THEM TO FRM A CHAIN
        sll.head.next=second;
        second.next =third;
        third.next=fourth;

        sll.display();
    }
}
