
public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<n-1;i++){
            int min_inx=i;
            for(int j=i+1;j<n;j++){
                if(arr[min_inx]>arr[j]){
                    min_inx=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[min_inx];
            arr[min_inx]=temp;
        }

        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }

    }
}
