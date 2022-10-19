struct Node{
    Node* links[2];
    bool containsKey(int key){
        return links[key] != NULL;
    }
    void put(int key, Node* node){
        links[key]=node;
    }
    Node* get(int key){
        return links[key];
    }
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            //get bit
            int bit = num>>i & 1;
            if(!node->containsKey(bit)) node->put(bit,new Node());
            node=node->get(bit);
        }
    }
    int findMaxXor(int num){
        Node *node=root;
        int maxxor;
        for(int i=31;i>=0;i--){
            //get bit
            int bit = num>>i & 1;
            if(node->containsKey(!bit)) {
                //set bit
                maxxor = maxxor | 1<<i;
                node=node->get(!bit);
            }
            else node=node->get(bit);
        }
        return maxxor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(begin(nums),end(nums));
        vector<pair<int, pair<int,int>>> offQ;
        // offQ = { {mi, {xi,i}} }
        int i=0;
        for(auto it: queries){
            offQ.push_back({it[1],{it[0],i++}});
        }
        sort(begin(offQ),end(offQ));
        vector<int>ans(offQ.size(),0);
        int ind=0;
        Trie trie;
        
        for(int i=0;i<offQ.size();i++){
            int mi=offQ[i].first;
            int xi=offQ[i].second.first;
            int Qind=offQ[i].second.second;
            while(ind<nums.size() && nums[ind]<=mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) ans[Qind]=-1;
            else ans[Qind] = trie.findMaxXor(xi);
        }
        return ans;
    }
};