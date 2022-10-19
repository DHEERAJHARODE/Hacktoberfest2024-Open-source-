#include<bits/stdc++.h>
struct node{
    int v,u,wt;
    node (int v, int u, int wt){
        v = v;
        u = u;
        wt = wt;
    }
};

bool mycmp(node a, node b){
    return a.wt < b.wt;
}

//DISJOIINT SET
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++; 
    }
}
//DISJOINT SET

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<node> mytree;
    for(auto it:graph){
        mytree.push_back({it[0],it[1],it[2]});
    }
    sort(begin(mytree), end(mytree), mycmp);
    
    int sum=0;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) 
        parent[i] = i; 
    //for disjoint set
    vector<int> rank(n+1, 0); 
    
    for(auto it:mytree){
        if(findPar(it.v,parent) != findPar(it.u,parent)){
            sum += it.wt;
            unionn(it.u, it.v, parent, rank);
        }
    }
    return sum;
}