vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int> st;
        vector<int> ans(n,-1);
        unordered_map<int,int> umap;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()<=nums2[i]) st.pop();
            if(!st.empty()) {
                umap[nums2[i]]=st.top();
                ans[i]=st.top();
            }
            st.push(nums2[i]);
        }
        
        
        int m=nums1.size();
        vector<int> res;
        
        for(int i=0;i<m;i++){
            if(umap[nums1[i]]==0) res.push_back(-1);
            else res.push_back(umap[nums1[i]]);
        }
        return res;
    }