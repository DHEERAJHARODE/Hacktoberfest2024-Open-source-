#include<stdio.h>
#include <stdlib.h>

int A[] = {1,2,3,4,5,6};
int tree[100]={0};

int fuc(int a,int b)
{
	return a+b;
}

void build(int node, int start, int end)
{
	if(start == end)
        tree[node] = A[start];
    else
    {
        int mid = (start + end) / 2;        
        build(2*node+1, start, mid);     
        build(2*node+2, mid+1, end);   
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node +1] + tree[2*node+2];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l)
        return 0;
    if(l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2*node +1, start, mid, l, r);
    int p2 = query(2*node+2, mid+1, end, l, r);
    return (p1 + p2);
}

int main()
{
	build(0,0,5);
	for(int i=0;tree[i]!=0;i++)
		printf("%d ",tree[i]);
	printf("\n");
}