int search(vector<int>& nums, int t) {
        int beg=0,end=nums.size()-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            int m=nums[mid],b=nums[beg],e=nums[end];
            if(m==t) return mid;
            else if(m>=b){//t maybe in first inc arr
                if(t>=b and t<=m) end=mid-1;
                else beg=mid+1;
            }
            else{
                if(t>=m and t<=e) beg=mid+1;
                else end=mid-1;
            }
        }
        return -1;
    }