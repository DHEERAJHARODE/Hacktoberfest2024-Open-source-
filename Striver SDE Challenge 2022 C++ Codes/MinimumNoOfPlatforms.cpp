int calculateMinPatforms(int at[], int dt[], int n) {
    int p=1; //train 1 is at pf 1
    int count=1;
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0; //i for at, j for dt
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        p=max(p,count);
    }
    return p;
}