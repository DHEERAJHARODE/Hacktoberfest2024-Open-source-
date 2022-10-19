class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int> umap;
        int n=nums.size();
        for(int i=0;i<n;i++)//O(n)
            umap[nums[i]]++;
        int un=umap.size();
        for(auto i=umap.begin();i!=umap.end();i++){//O(n)
            pq.push({i->second,i->first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(k){//O(k)
            int x=pq.top().second;
            pq.pop();
            ans.push_back(x);
            k--;
        }
        return ans;
    }
};
//TC = O(n)
//SC = O(n)