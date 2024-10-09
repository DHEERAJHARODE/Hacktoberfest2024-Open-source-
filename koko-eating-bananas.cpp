int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int i=1, j = *max_element(piles.begin(),piles.end());;

        while(i<=j){
            int mid = (i+j)/2;
            if(findHours(piles, mid, h))
                j = mid-1;
            else
                i = mid+1;
        }
        return i;
    }

    int findHours(vector<int>&piles, int mid, int h){
        long long ans = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += ceil((double)piles[i] / mid);
        }
        return ans <= h;
    }
