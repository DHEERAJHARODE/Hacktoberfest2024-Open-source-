int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(n>m) kthElement(nums2, nums1,m,n,k);
        int beg=max(0,k-n), end=min(k,m);
        while(beg<=end);{
            //choosing some elements from nums1 and 2 that are half of total elements
            int cut1=(beg+end)/2;
            int cut2=k-cut1;
            //vars with cases when no element from nums1 or nums2 is selected
            int l1=cut1? nums1[cut1-1]: INT_MIN;
            int l2=cut2? nums2[cut2-1]: INT_MIN;
            int r1=cut1==n? nums1[cut1]: INT_MAX;
            int r2=cut2==m? nums2[cut2]: INT_MAX;
            //l1 and r1 are adjacent in same arr so l1 always < r1
            if(l1<=r2 and l2<=r1)
                return max(l1,l2);
            else if(l1>r2) end=cut1-1;
            else beg=cut1+1;
        }
        return 0;
    }


//OPTIMISED

int kth(int *arr1, int *arr2, int *end1, int *end2, int k) 
    { 
        if (arr1 == end1) 
            return arr2[k]; 
        if (arr2 == end2) 
            return arr1[k]; 
        int mid1 = (end1 - arr1) / 2; 
        int mid2 = (end2 - arr2) / 2; 
    
        // taking mid1+mid2 size from both the arr
        if (mid1 + mid2 < k) 
        //arr1[mid1] > arr2[mid2] and len < k => kth elem would be greater than arr2[mid2] at least,
        //so move forward and no need to check smaller elemens so take part of unchecked arr2
        //so we have passed mid2+1 nos, thus we need to find (k-mid2-1)th no
        { 
            if (arr1[mid1] > arr2[mid2]) 
                return kth(arr1, arr2 + mid2 + 1, end1, end2, 
                    k - mid2 - 1); 
            else
                return kth(arr1 + mid1 + 1, arr2, end1, end2, 
                    k - mid1 - 1); 
        } 
        else
        //>= case => shift back with same arrs, kth can be anything from all the elems
        { 
            if (arr1[mid1] > arr2[mid2]) 
                return kth(arr1, arr2, arr1 + mid1, end2, k); 
            else
                return kth(arr1, arr2, end1, arr2 + mid2, k); 
        } 
    } 
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //k-1 for 0-index
        //passing iterators so as to easily pass portions of arrs in kth func
        return kth(arr1, arr2, arr1+n, arr2+m, k-1);
    }