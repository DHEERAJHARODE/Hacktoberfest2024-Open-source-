import java.util.*;
public class Main {
   
    public static void main(String[] args){
       
        int num ;
        boolean flag = false;
        try (Scanner sc = new Scanner(System.in)) {
       
                    do{
                        System.out.println("Enter Number:");
                            num = sc.nextInt();
                    } while(num<1);
       
                    double num2= Math.sqrt(num);
                    num2=Math.ceil(num2);
               
                for (int i = 2; i <= num2 ; ++i) {
                  
                  if (num % i == 0) {
                    flag = true;
                    break;
                  }
                }
           
                if (!flag)
                  System.out.println(num + " is a prime number.");
                else
                  System.out.println(num + " is not a prime number.");
        }  
    }
 }

