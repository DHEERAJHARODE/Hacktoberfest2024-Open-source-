/*
Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
 */
public class Solution {
    
  public static LinkedListNode<Integer> findmid (LinkedListNode<Integer> head){
      if(head==null)return head;
        LinkedListNode<Integer> fast = head;
        LinkedListNode<Integer> slow = head;
        while(fast.next!=null && fast.next.next!=null){
              slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
   public static LinkedListNode<Integer>  mergeTwoList (LinkedListNode<Integer> head1,LinkedListNode<Integer> head2){
    if(head1==null)return head2;
    if(head2==null)return head1;
      
        LinkedListNode<Integer> t1=head1;
        LinkedListNode<Integer> t2=head2;
        LinkedListNode<Integer> head=null,tail=null;
        
        if(t1.data<=t2.data){
            head=t1;
            tail=t1;
            t1=t1.next;
        }
        else{
            head=t2;
            tail=t2;
            t2=t2.next;
        }
        while(t1!=null && t2!=null){
            if(t1.data<=t2.data){
                tail.next=t1;
                tail=t1;
                t1=tail.next;
            }
            else{
                tail.next=t2;
                tail=t2;
                t2=tail.next;
              }
        }
            if(t1!=null){
                tail.next=t1;
            }
            else{
             tail.next=t2;
            }
           
         return head;
    }

    

	public static LinkedListNode<Integer> mergeSort(LinkedListNode<Integer> head) {
		 // base case
        if(head==null)return head;if(head.next==null)return head;
        
        // break linked List into two halves after finding the 
        LinkedListNode<Integer> midNode=findmid(head);
        
        LinkedListNode<Integer> left = head;
        LinkedListNode<Integer> right = midNode.next;
        midNode.next=null;
        
      LinkedListNode<Integer>  part1 = mergeSort(left);
       LinkedListNode<Integer>  part2 = mergeSort(right);
        
      // merge both left and right halves
        LinkedListNode<Integer> result =  mergeTwoList(part1,part2);
        return result;
        
        
	}

}
