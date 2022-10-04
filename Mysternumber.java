import java.util.Scanner;  
public class MysteryNumberExample1  
{  
static int reverse(int x)  
{       
String str = Integer.toString(x);  
String string="";  
for(int i=str.length()-1;i>=0;i--)  
{      
string=string+str.charAt(i);  
}   
int rev=Integer.parseInt(str);  
return rev;  
}  
static boolean isMysteryNo(int num)  
{  
for (int i=1; i <= num/2; i++)  
{  
int j = reverse(i);  
if (i + j == num)  
{  
System.out.println( i + " " + j);  
System.out.println(num+ " is a mystery number.");  
return true;  
}  
}  
System.out.println("The given number is not a mystery number.");  
return false;  
}  
{  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter a number: ");  
int num = sc.nextInt();  
isMysteryNo(num);  
}  
}  