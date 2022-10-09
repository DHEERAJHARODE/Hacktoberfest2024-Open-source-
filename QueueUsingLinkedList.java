class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
    }
}
class QueueLinkedList{
    Node front,rear;
    void enqueue(int data){
         Node newNode = new Node(data);
         if(front==null){
             front=rear=newNode;
             System.out.println("Inserted data "+data);
         }
         else
         {
        rear.next=newNode;
         rear=newNode;
         System.out.println("Inserted data "+rear.data);
    }
    }
    int dequeue(){
        if(front==null){
            System.out.println("Queue is Empty");
        }
    else{
        int results = front.data;
        front=front.next;
        return results;
    }
    return -1;
}
    
    void traverse()
{
   if(front == null)
     System.out.println("QUEUE IS EMPTY");
   else{
      Node temp = front;
      while(temp.next != null){
	 System.out.println(temp.data);
	 temp=front.next;
      }
   }
}
}
public class Main
{
	public static void main(String[] args) {
	QueueLinkedList q = new QueueLinkedList();
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
q.traverse();
	}
}
