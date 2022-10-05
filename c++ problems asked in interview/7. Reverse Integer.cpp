class Solution {
public:
    int reverse(int x) 
    {
        long long int rev=0;
        vector <int> v;
        
        while(x!=0){
            int digit = x%10;
            v.push_back(digit);
            x=x/10;
        }
        
        int i = v.size();
        
        for(int j=0 ; j<v.size() ; j++){
            rev += pow(10,i-1)*v[j];
            i--;
        }
        
        if(rev>INT_MAX || rev<INT_MIN){
            return 0;
        }
        
        return rev;
        
    }
};