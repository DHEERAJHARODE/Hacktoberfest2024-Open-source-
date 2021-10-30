#include <bits/stdc++.h>
using namespace std;
class Stock
{
    string name;
    int n;
    int n2;
    int p;
    long t;
    public:
    Stock(int,int,string);
    ~Stock();
    void buyStock(int,int);
    void sellStock(int,int);
    void updateShP(int);
    void show();
    void setT();
};
     Stock::Stock(int a, int b, string s)
    {
        name=s;
        n=a;
        n2=n;
        p=b;
        t=0;
        t-=a*b;
    }
    void Stock::buyStock(int a, int b)
    {
        n+=a;
        p=b;
        setT();
        show();
    }
    void Stock::sellStock(int a,int b)
    {
        if(a<=n)
        {
        n-=a;
        p=b;
        setT();
        }
        else
        cout<<"Enter valid number of stocks"<<endl;
        show();
    }
    void Stock::updateShP(int a)
    {
        p=a;
        show();
    }
    void Stock::show()
    {
        cout<<"Stock: "<<name<<endl;
        cout<<"Price: "<<p<<endl;
        cout<<"Number: "<<n<<endl;
        cout<<"Total: "<<t<<endl;
    }
    void Stock::setT()
    {
        if(n2<n)
        t+=(n2-n)*p;
        else
        t-=(n2-n)*p;
        n2=n;
    }
    Stock::~Stock()
    {
        delete n;
        delete p;
        delete name;
        delete t;
    }
    int main()
    {
        string na;
        int p;
        int n;
        int i=0;
        int k;
        cout<<"Enter the name"<<endl;
        cin.ignore();
        getline(cin,na);
        cout<<"Enter the price"<<endl;
        cin>>p;
        cout<<"Enter the Quantity"<<endl;
        cin>>n;
        Stock s(n,p,na);
        while(i==0)
        {
            cout<<"\n STOCK FUNCTIONS\n 1.Buy Stock\n 2.Sell Stock\n 3.Update Price \n4.Display Info\n5.Exit \n";
            cin>>k;
            switch(k)
            {
                case 1:
                cout<<"Enter the price"<<endl;
                cin>>p;
                cout<<"Enter the Quantity"<<endl;
                cin>>n;
                s.buyStock(n,p);
                break;
                case 2:
                cout<<"Enter the price"<<endl;
                cin>>p;
                cout<<"Enter the Quantity"<<endl;
                cin>>n;
                s.sellStock(n,p);
                break;
                case 3:
                cout<<"Enter the price"<<endl;
                cin>>p;
                s.updateShP(p);
                break;
                case 4:
                s.show();
                break;
                case 5:
                i=1;
            }


            }
        }
