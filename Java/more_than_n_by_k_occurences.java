import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{
    public static void main (String[] args) 
    {
        int arr[] = new int[]{10, 10, 20, 30, 20, 10,10};
        
        int n = arr.length;
        int k=2;
        printNByK(arr, n, k);
        
    }
    
    static void printNByK(int arr[], int n, int k)
    {
        HashMap<Integer,Integer> m=new HashMap<Integer,Integer>();
        
        for(int x:arr)
            m.put(x,m.getOrDefault(x,0)+1);
        for(Map.Entry <Integer,Integer> e:m.entrySet())
            if(e.getValue()>n/k)
                System.out.print(e.getKey()+" ");
    }
}
