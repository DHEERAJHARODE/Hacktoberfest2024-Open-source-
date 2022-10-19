#include <bits/stdc++.h>
using namespace std;
int main()
{
    int bn, pn;
    cout << " Enter number of block: ";
    cin >> bn;
    cout << " Enter number of processor: ";
    cin >> pn;
    int pro[pn], blk[bn], bsize[bn], psize[pn], tmpbsize[bn], fit[pn], f = 0;
    for (int i = 0; i < pn; i++)
    {
        fit[i] = -1;
    }
    for (int i = 0; i < bn; i++)
    {
        blk[i] = i + 1;
        cout << " Enter size of Block " << i + 1 << ": ";
        cin >> bsize[i];
        tmpbsize[i] = bsize[i];
    }
    for (int i = 0; i < pn; i++)
    {
        pro[i] = i + 1;
        cout << " Enter size of processor " << i + 1 << ": ";
        cin >> psize[i];
    }
    for (int i = 0; i < bn; i++)
    {
        for (int j = i + 1; j < bn; j++)
        {
            if (bsize[i] > bsize[j])
            {
                swap(bsize[i], bsize[j]);
                swap(blk[i], blk[j]);
            }
        }
    }
    for (int i = 0; i < pn; i++)
    {
        for (int j = 0; j < bn; j++)
        {
            if (psize[i] <= bsize[j])
            {
                fit[i] = blk[j];
                bsize[j] -= psize[i];
                break;
            }
        }
    }
    cout << " \nPro\tBlock\tBlock Size\n";
    for (int i = 0; i < pn; i++)
    {
        if (fit[i] < 0)
        {
            cout << " P" << pro[i] << " \tNot Allocated" << endl;
        }
        else
        {
            cout << " P" << pro[i] << "\t" << fit[i] << "\t" << tmpbsize[fit[i] - 1] << endl;
        }
    }
}
