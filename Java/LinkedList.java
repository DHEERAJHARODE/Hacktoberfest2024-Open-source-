import java.util.*;
class ListNode
{
int x;
ListNode next;

ListNode(int x)
{
    this.x=x;
    this.next=null;
}

}


 class Solution{
    //Creates a new node with given data x , inserts Scanner
    //at the end of LL h and returns head of changed LL.
    ListNode insertEnd(ListNode h, int x){
        
        ListNode nn=new ListNode(x);
        if(h==null)
        {
            return nn;
        }
        
        ListNode temp=h;
        while(temp.next!=null)
        {
            temp=temp.next;
            
        }
        temp.next=nn;
        return h;
        
    }
    
    void printLL(ListNode h){
        ListNode temp=h;
        while(temp!=null)
        {
        System.out.print(temp.x+" ");
        temp=temp.next;
        }

    }
    
ListNode readList(){
    
    ListNode h=null;
   int n=Main.sc.nextInt();
    for(int i=0;i<n;i++)
    {
        int x=Main.sc.nextInt();
        h=insertEnd(h,x);
    }
    return h;
        
    }
    
   long sumLL(ListNode h){
        ListNode temp=h;
        long sum=0;
        while(temp!=null)
        {
            sum+=temp.x;

        temp=temp.next;
        }
       return sum;
   } 
   
   void printRevLL(ListNode h){
       Stack<Integer> stk= new Stack<>();
        ListNode temp=h;
        while(temp!=null)
        {
        stk.push(temp.x);     
        temp=temp.next;
        }
       while(!stk.isEmpty())
       {
           System.out.print(stk.pop()+" ");
       }
       
       
   }
   
   
   ListNode merge(List<ListNode> lists){

        if(lists==null)
         return null;
       
       PriorityQueue<ListNode> pq= new PriorityQueue<>(  (h1,h2)->{
           return h1.x-h2.x;
       }   );
       
       for(ListNode h:lists){
           
       if(h!=null)
           pq.add(h);
       }
       
     ListNode dm= new ListNode(-1);
     ListNode tp=dm;
     while(!pq.isEmpty()){
         
         ListNode mn= pq.poll();
         tp.next=mn;
         tp=tp.next;
         if(mn.next!=null){
             pq.add(mn.next);
         }
     }
       
       return dm.next;    
   }
   
   
}


public class Main{
 static Scanner sc= new Scanner(System.in);

    public static void main(String[]args){
        Solution sol= new Solution();
        List<ListNode> lists= new ArrayList<>();
        int n=sc.nextInt();
        while(n-->0){
         ListNode h=sol.readList();
         lists.add(h);

        }
        // for(ListNode h:lists){
            
        //   sol.printLL(h); 
        //   System.out.println();
        //   sol.printRevLL(h);
        //  System.out.println();

        // long sum=  sol.sumLL(h);


        //   System.out.println(sum);
          
        //       }
        
        ListNode ans= sol.merge(lists);
        sol.printLL(ans);
        
            
    

    }
}
