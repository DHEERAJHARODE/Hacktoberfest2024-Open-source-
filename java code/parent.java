//overloading
class parent
{
    int x=5,y=6,c;
    void sum()
    {
        c=x+y;
        System.out.println(c);
    }
    void display()
    {
        System.out.println(c);
    }
}
class child extends parent
{
    int mult;
    void cal()
    {
        int x1=6,y1=9;
        mult=x1*y1;
    }
    void display()
    {
        System.out.println(mult);
    }
}
class result
{
    public static void main(String args[])
    {
        child d=new child();
        d.display();
    }
}