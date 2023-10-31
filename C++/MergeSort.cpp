void merge(int arr[], int l, int m, int r)
    {
         // Your code here
       
         int i=l;
         int j=m+1;
         //dynamic array
         int s=r-l+1;
         vector<int> temp(s);
         int k=0;
         while(i<=m && j<=r){
             if(arr[i]<arr[j]){
                 temp[k]=arr[i];
                 k++;i++;
             }
             else if(arr[j]<arr[i]){
                 temp[k]=arr[j];
                 k++;j++;
             }
             else{
                 temp[k++]=arr[i];
                 i++;
                 temp[k++]=arr[j];
                 j++;
             }
         }
         
         while(i<=m){
             temp[k++]=arr[i++];
         }
          while(j<=r){
             temp[k++]=arr[j++];
         }
         int n=l;
         for(int it=0;it<s;it++){
             arr[n++]=temp[it];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
