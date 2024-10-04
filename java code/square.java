//static function
class square
{
    static int sq;
    static void sq_int(int r)
    {
        //int sq;
        sq=r*r;
        System.out.println(sq);
    }
}
class Square1
{
    public static void main(String args[])
    {
        square.sq_int(2);
        System.out.println(square.sq);
    }
}