import java.util.*;
class Fibonacci
{
	void getResult(int n)
	{
		int a=0,b=1;
		int c=a+b;
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		for(int i=2;i<=n;i++)
		{
			a=b;
			b=c;
			c=a+b;
			System.out.println(c);
		}
	}
}
class Fibo
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter n terms :");
		int num=sc.nextInt();
		Fibonacci obj=new Fibonacci();
		obj.getResult(num);
	}
}
