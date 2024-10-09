#include<bits/stdc++.h>
using namespace std;
string simplifyPath(string path) {
    path.push_back('/');
    stack<string> st;
    string temp = "";
    for(int i=0;i<path.size();i++){
        if(path[i] == '/'){
            if(temp ==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(temp != "." && temp !=""){
                st.push(temp);
            }
            temp = "";
        }
        else{
            temp.push_back(path[i]);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans = "/" + st.top() + ans;
        st.pop();
    }
    return (ans == "" ? "/" : ans);
}


int main(){
    string path = "/home//foo/";
    cout<<simplifyPath(path)<<endl;
    return 0;
}