double median(int *arr1, int *arr2, int *end1, int *end2, int k){
        if(arr1 == end1) return arr2[k];
        if(arr2 == end2) return arr1[k];
        
        int mid1 = (end1-arr1)/2, mid2 = (end2-arr2)/2;
        
        if(mid1+mid2 < k){
            if(arr1[mid1] > arr2[mid2])
                return median(arr1, arr2+mid2+1, end1, end2, k-mid2-1);
            else
                return median(arr1+mid1+1, arr2, end1, end2, k-mid1-1);
        }
        else{
            if(arr1[mid1] > arr2[mid2])
                return median(arr1, arr2, arr1+mid1, end2, k);
            else
                return median(arr1, arr2, end1, arr2+mid2, k);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int k = n + m;
        
        if(n==0){
            if(m%2==0) return ((double)nums2[m/2]+(double)nums2[m/2-1])/(double)2;
            else return nums2[m/2];
        }
        if(m==0){
            if(n%2==0) return ((double)nums1[n/2]+(double)nums1[n/2-1])/(double)2;
            else return nums1[n/2];
        }
        //vector to arr
        int arr1[n], arr2[m];
        double temp;
        copy(nums1.begin(), nums1.end(), arr1);
        copy(nums2.begin(), nums2.end(), arr2);
        if(k%2 != 0) return median(arr1, arr2, arr1+n, arr2+m, k/2);
        else{
            temp = median(arr1, arr2, arr1+n, arr2+m, k/2-1) + median(arr1, arr2, arr1+n, arr2+m, k/2);
            return temp/2;
        }
    }