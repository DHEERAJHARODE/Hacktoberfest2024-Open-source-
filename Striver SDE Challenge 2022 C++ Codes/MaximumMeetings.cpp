#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) {
    int n=start.size();
    pair<int, int> acts[n];
    for(int i=0;i<n;i++){
        acts[i].first=end[i];
        acts[i].second=start[i];
    }
    sort(acts, acts+n);
    int c=1;//1st act selected
    int last=acts[0].first;
    for(int i=1;i<n;i++){
        if(acts[i].second>=last){
            c++;
            last=acts[i].first;
        }
    }
    return c;
}