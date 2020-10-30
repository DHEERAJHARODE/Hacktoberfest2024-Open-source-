//Converts any number between 0-9999 (inclusive) to words 
#include<conio.h>
#include<iostream.h>

void words(int n, int c, int r)
{
  if(n==0 && c==1)
  {
     cout<<"Zero"<<endl;
     return;
  }
  if(!r)
     return;

  char singled[][10]={"one","two","three","four","five","six","seven","eight","nine"};
  char ones[][20]={"eleven","twelve","thirteen"};
  char doubled[][10]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
 // char threed[][10]={"hunderd","thousand"};

  switch(c)
  {
     case 1: cout<<" "<<singled[r-1];
	     break;
     case 2: if(n>=20 || n==10)
	     {
	       cout<<" "<<doubled[r%10-1];
	       words(n/10,c-1,r/10);
	     }
	     else if(n>=14)
	       cout<<" "<<singled[r%10-1]<<"teen";
	     else
	       cout<<" "<<ones[n%10-1];
	     break;
     case 3: words(n,1,r%10);
	     cout<<" "<<"hundred";
	     words(n%100,c-1,r/10);
	     break;
     case 4: words(n,1,r%10);
	     cout<<" "<<"thousand";
	     words(n%1000,c-1,r/10);
	     break;
  }
}
void main()
{
  clrscr();
  cout<<"Enter a number: ";
  int n;
  cin>>n;
  int n1=n;
  int count=0, rev=0;
  while(n1!=0)
  {
    rev=rev*10+(n1%10);
    count++;
    n1=n1/10;
  }
  words(n,count,rev);
  getch();
}