class TLNode{
 	int data;
 	TLNode left,right;
	 
 	TLNode(int d)
 	{
	   data=d;
  }
}

public class binaryTree{
	static void preOrder(TLNode r){
		if(r==null)
		    return;
		
		System.out.print(r.data+" ");
		
		preorder(r.left);
		preorder(r.right);
	}
	
	static void inorder(TLNode r){
		if(r==null)
		    return;
		
		inorder(r.left);
		System.out.print(r.data+" ");
		inorder(r.right);
		
   }
	
	static void postorder(TLNode r){
		if(r==null)
		    return;
		
		postorder(r.left);
		postorder(r.right);
		System.out.print(r.data+" ");

   }
	public static void main(String[] args){
		
		TLNode root=new TLNode(1);
		
		root.left=new TLNode(2);
		root.right=new TLNode(3);
		
		root.left.left=new TLNode(4);
		root.left.right=new TLNode(5);
		
		root.right.left=new TLNode(6);
		root.right.right=new TLNode(7);
		preorder(root);
		System.out.println();
		
		inorder(root);
		System.out.println();
		
		postorder(root);
		System.out.println();		
	}
	
}
