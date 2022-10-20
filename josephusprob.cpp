//Github username : Disha Khanapurkar

using System;
class Test
{
 
  // Method for finding the winning child.
  private int josephus(int n, int k)
  {
    int sum = 0;
 
    // For finding out the removed
    // chairs in each iteration
    for(int i = 2; i <= n; i++)
    {
      sum = (sum + k) % i;
    }
 
    return sum+1;
  }
 
  // Driver Program to test above method
  public static void Main(String[] args)
  {
    int n = 14;
    int k = 2;
    Test obj = new Test();
    Console.WriteLine(obj.josephus(n, k));
  }
}
