import java.util.*;
class PrimeNum
{
	void getResult(int r1,int r2)
	{
		System.out.println("Prime numbers are:");
		for(int i=1;i<=100;i++)
		{
			int c=0;
			for(int j=2;j<i;j++)
			{
				if(i%j==0)
					c=c+1;
			}
			if(c==0)
				System.out.println(i);
		}
	}
}
class Prime
{
	public static void main(String args[])
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter range from:");
		int a=sc.nextInt();
		System.out.println("Enter range to:");
		int b=sc.nextInt();
		PrimeNum obj=new PrimeNum();
		obj.getResult(a,b);
	}
}