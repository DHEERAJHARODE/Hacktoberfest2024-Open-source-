bool isValidParenthesis(string s)
{
    stack<int> st;
    for(auto b:s){
        if(b=='(' || b=='{' || b=='[') st.push(b);
        else{
            if(st.empty() || (st.top()=='(' && b!=')') || (st.top()=='{' && b!='}') || (st.top()=='[' && b!=']')) return false;
            else st.pop();
        }
    }
    return st.empty();
}