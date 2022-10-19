double findNthRootOfM(int n, long long m) {
	double beg=1, end=m;
    while(end-beg>1e-6){ //which implies that mid would be v close to ans and would be acceptable as answer with 6 decimal places
        double mid=beg+(end-beg)/2.0;
        if(power(mid,n) < m) beg=mid;
        else end=mid;
    }
    return pow(m, (double)(1/(double)n));
}