int removeDuplicates(vector<int> &arr, int n) {
	int j=0,k=1;
    int key=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]!=key){
            arr[++j]=arr[i];
            key=arr[i];
            k++;
        }
    }
    return k;
}