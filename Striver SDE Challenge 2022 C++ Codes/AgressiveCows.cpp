#include<bits/stdc++.h>
bool isPossible(int t, vector<int> pos, int c){
    int prev=pos[0];
    c--;
    for(int i=1;i<pos.size();i++){
        if(c==0) return true;
        if(abs(pos[i]-prev)>=t){
            c--;
            prev=pos[i];
        } 
    }
    if(c>0) return false;
    else return true;
}
int chessTournament(vector<int> pos, int n, int c){
    sort(pos.begin(),pos.end());
	int beg=1;
    int end=*max_element(pos.begin(),pos.end())-*min_element(pos.begin(),pos.end());
    while(beg<=end){
        int mid=(beg+end)/2;
        if(isPossible(mid,pos,c)) beg=mid+1;
        else end=mid-1;
    }
    return end;
}