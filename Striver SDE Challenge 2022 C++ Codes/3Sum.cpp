if(nums.size()<=2) return {};
        sort(nums.begin(),nums.end());
        if(nums[0]>0) return {};
        vector<vector<int>> ans;
        unordered_map<int,int> umap;
        
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]=i;
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            for(int j=i+1;j<nums.size()-1;j++){
                int key=-1*(nums[i]+nums[j]);
                if(umap.count(key) && umap.find(key)->second > j)
                    ans.push_back({nums[i],nums[j],key});
                j=umap.find(nums[j])->second;
            }
            i=umap.find(nums[i])->second;
        }
        return ans;