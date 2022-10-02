#include<iostream>
using namespace std;

class CTest3
{
    private:
    int iCount;

    public:
    CTest3()
    {
        iCount = 1;
    }

    CTest3(CTest3 &obj)
    {
        iCount = obj.iCount;
        iCount++;
        cout<<iCount;
    }
    void fun(CTest3 obj)
    {
        int temp = obj.iCount;
    }
};

int main()
{
    CTest3 obj1;
    CTest3 obj2 = obj1;
    obj2.fun(obj1);
    return 0;
}
