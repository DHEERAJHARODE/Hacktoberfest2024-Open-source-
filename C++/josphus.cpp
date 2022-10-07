class Solution {
public:
    int josphusProblem(int n, int k) {
        if(n==0)
        {
            return 0;
        }
        else
        {
            return (josphusProblem(n-1,k)+k+1)%n;
        }
    }
};
