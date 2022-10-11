import java.util.*;
public class bubble_new
{
    public static void main()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter 10 Numbers");
        int a[]=new int[10];
        for(int i=0;i<10;i++)
        {
            a[i]=in.nextInt();
        }
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<10-j-1;k++)
            {
                if(a[k]>a[k+1]){
                    a[k]=a[k]+a[k+1];
                    a[k+1]=a[k]-a[k+1];
                    a[k]=a[k]-a[k+1];
                }
            }
        }
        System.out.println("Sorted Array: ");
        for(int l=0;l<10;l++)
            System.out.print(a[l]+" ");
    }
}
