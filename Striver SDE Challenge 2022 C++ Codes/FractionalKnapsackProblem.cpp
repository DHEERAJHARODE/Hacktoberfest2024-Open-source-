#include <bits/stdc++.h>
bool compare(pair<int, int> a, pair<int, int> b){
    return (double)a.second/(double)a.first > (double)b.second/(double)b.first;
}
double maximumValue (vector<pair<int, int>>& items, int n, int W)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),compare);
    int w=0;
    double pf=0;
    for(int i=0;i<n;i++){
        if(w+items[i].first<=W){
            pf+=items[i].second;
            w+=items[i].first;
        }
        else{
            int rem=W-w;
            pf+=(items[i].second/(double)items[i].first)*(double)rem;
            break;
        }
    }
    return pf;
}