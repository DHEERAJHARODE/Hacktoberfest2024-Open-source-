class BuyOrSellStock{
    public static int maxProfit(int[] prices)
   {
       int n = prices.length;
       int answer = 0;
       for (int i = 0; i < n; i++)
       {
           for (int j = i + 1; j < n; j++)
           {
               answer=Math.max(answer, prices[j] - prices[i]);
           }
       }
       return answer;
   }
   public static void main(String[] args) {
 
   int[] prices = {7, 1, 5, 3, 6, 4};
   System.out.println(maxProfit(prices));
}
}