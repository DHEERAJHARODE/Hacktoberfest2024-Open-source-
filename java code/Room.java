import java.util.*;
class Room
{
	int l,b;
	void getResult(int length,int breadth)
	{
		l=length;
		b=breadth;
		System.out.println(l*b);
	}
}
class Area
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Length :");
		int len=sc.nextInt();
		System.out.println("Enter Breadth :");
		int bred=sc.nextInt();
		Room obj = new Room();
		obj.getResult(len,bred);
	}
}