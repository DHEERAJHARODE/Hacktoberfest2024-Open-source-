struct Node{
    Node *links[2];
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    
    void put(int bit, Node* node){
        links[bit] = node;
    }
    
    Node *get(int bit){
        return links[bit];
    }
};

class Trie {
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node=root;
        //32-bit int
        for(int i=31;i>=0;i--){
            //get bit
            int bit = num>>i & 1;
            //insert current bit of num
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int findMaxXor(int num){
        Node* node=root;
        int maxNow=0;
        //32-bit int
        for(int i=31;i>=0;i--){
            //get bit
            int bit = num>>i & 1;
            //check if opposite bit present as that gives max xor
            if(node->containsKey(!bit)){
                //set bit
                maxNow = maxNow | 1<<i;
                node = node->get(!bit);
            }
            //else get what you have
            else node = node->get(bit);
        }
        return maxNow;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxXor=0;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        for(auto &it: nums){
            maxXor = max(maxXor,trie.findMaxXor(it));
        }
        return maxXor;
    }
};