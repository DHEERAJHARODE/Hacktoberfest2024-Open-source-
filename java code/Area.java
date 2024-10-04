//overloading
class Area {
    static int cal(int number1, int number2) 
    {
        return number1 * number2;
    }
    static double cal(double number) 
    {
        return 3.14*number*number;
    }
    static int cal(int number) 
    {
        return number * number;
    }
}

class OL {
    public static void main(String[] args) 
    {
        System.out.println(Area.cal(2,2));        
        System.out.println(Area.cal(2.0));      
        System.out.println(Area.cal(2));     
    }
}
