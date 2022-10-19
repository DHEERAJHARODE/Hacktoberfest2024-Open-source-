stack<pair<int,int>> st;
    int ind;
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind=ind+1;
        while(!st.empty() and st.top().second<=price) st.pop();
        if(st.empty()){
            st.push({ind,price});
            return ind+1;
        }
        int ind_prev=st.top().first;
        st.push({ind,price});
        return ind-ind_prev;
    }