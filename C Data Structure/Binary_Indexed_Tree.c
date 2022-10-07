#include<stdio.h>
#include<stdlib.h>

int b[1000], a[1000], n;
void update(int x, int delta)
{
      for(;x <= n;x += (x&(-x)))
        b[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= (x&(-x)))
        sum += b[x];
     return sum;
}

int main()
{
     scanf("%d", &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf("%d", &a[i]);
           update(i, a[i]);
     }
     printf("sum of first 4 elements is %d\n", query(4));
     printf("sum of all elements in range [2, 4] is %d\n",(query(4)-query(2-1)));
     return 0;
}