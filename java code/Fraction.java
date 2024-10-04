import java.util.*;
class Fraction
{
    double n,d;
    Fraction(double numerator,double denominator)
    {
        n=numerator;
        d=denominator;
    }
    double fra()
    {
        double ans=n/d;
        return(ans);
    }
}
class Frac
{
    public static void main(String args[])
    {
        Fraction ob1 = new Fraction(1.0,2.0);
        double a=ob1.fra();
        System.out.println(a);
        Fraction ob2 = new Fraction(3.0,4.0);
        double b=ob2.fra();
        System.out.println(b);
        Fraction ob3 = new Fraction(5.0,6.0);
        double c=ob3.fra();
        System.out.println(c);
    }
}