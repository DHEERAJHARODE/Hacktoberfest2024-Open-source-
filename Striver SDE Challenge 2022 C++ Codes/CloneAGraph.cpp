class Solution {
public:
    
    void dfs(Node* cur, Node* copyNb, vector<Node*>& vtd){
        
        vtd[copyNb->val]=copyNb;
        
        for(auto x:cur->neighbors){
            if(!vtd[x->val]){
                Node* y = new Node(x->val);
                (copyNb->neighbors).push_back(y);
                dfs(x,y,vtd);
            }
            else (copyNb->neighbors).push_back(vtd[x->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node) return NULL;
        
        vector<Node*> vtd(101, NULL);
        Node* copy = new Node(node->val);
        vtd[node->val]=copy;
        
        for(auto cur:node->neighbors){
            
            if(!vtd[cur->val]){
                Node* copyNb = new Node(cur->val);
                (copy->neighbors).push_back(copyNb);
                dfs(cur,copyNb,vtd);
            }
            
            else (copy->neighbors).push_back(vtd[cur->val]);
        }
        return copy;
    }