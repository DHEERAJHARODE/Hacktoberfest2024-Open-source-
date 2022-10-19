#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    if(!root) return ans;
    stack<pair<BinaryTreeNode<int> *,int>>st;
    vector<int> post,pre,in;
    st.push({root,1});
    while(!st.empty()){
        auto p=st.top();
        st.pop();
        BinaryTreeNode<int> *f=p.first;
        if(p.second==1){
            p.second++;
            st.push(p);
            pre.push_back(f->data);
            if(f->left) st.push({f->left,1});
        }
        else if(p.second==2){
            p.second++;
            st.push(p);
            in.push_back(f->data);
            if(f->right) st.push({f->right,1});
        }
        else if(p.second==3) post.push_back(f->data);
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}