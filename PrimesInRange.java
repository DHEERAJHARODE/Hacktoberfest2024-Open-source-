// given two numbers print all primes between them (inclusive)
public class PrimesInRange {
  public static main(String[]args){
    PrimesInRange(20,30);
  }

  public static void PrimesInRange(int lowBound, int upBound){
    for(int i = lowBound, into i <= upBound;i++){
      if(isPrime(i)){
        System.out.println(i);
      }
    }
  }

    public static boolean isPrime(int a){
      for(int i = 0; i <= Math.sqrt(a);i++){
        if(a%i==0){
          return true;
        }
      }
      return false;
    }
}
