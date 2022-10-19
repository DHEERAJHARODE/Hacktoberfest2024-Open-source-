#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    // vector to keep track of current index of each vector
    vector<int> vec(k,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mpq;

    while(--k){
        pair<int,int> p;
        p.first=kArrays[k][0];
        p.second=k;
        mpq.push(p);
    }
    while(!mpq.empty()){
        pair<int,int> x = mpq.top();
        mpq.pop();
        ans.push_back(x.first);
        int curr_vec = x.second; //vector no of pushed value
        int curr_vec_len = kArrays[curr_vec].size(); //size of vector of pushed value
        if(vec[curr_vec]+1 < curr_vec_len){
            
            pair<int,int> p;
            p.first=kArrays[curr_vec][vec[curr_vec]+1];
            p.second=curr_vec;
            mpq.push(p);
        }
        vec[curr_vec] += 1;
    }
    return ans;
}

//better way
ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = l1->val <= l2->val? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++)
            head = merge2Lists(head, lists[i]);
        
        return head;
    }