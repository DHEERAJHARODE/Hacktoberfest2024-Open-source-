#include <bits/stdc++.h>
bool static comparison(vector<int> a, vector<int> b) {
         return (a[1] > b[1]);
      }
int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    int c=0,pf=0;
    sort(jobs.begin(),jobs.end(), comparison);
    int maxd=0;
    for(int i=0;i<n;i++)
        maxd=max(maxd,jobs[i][0]);
    vector<int> slot(maxd,-1);
    for(int i=0;i<n;i++){
	  //try to fit the job in the max slot
        //if not possibe then fit in slot below
        for(int j=jobs[i][0]-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                pf+=jobs[i][1];
                c++;
                break;
            }
        }
    }
    return pf;
}
