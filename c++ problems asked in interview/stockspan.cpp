#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  int a[n],s[n];
  for(int i=0;i <n; i++) cin >> a[i];
  stack <int>st;
  st.push(0);

  s[0]=1;

  for(int i=1; i<n; i++){
    while(!st.empty() && a[st.top()] <= a[i])
      st.pop();

    s[i] = st.empty() ? (i+1) : (i-st.top());

    st.push(i);
    cout << s[i] << " ";
  }
}

int main(){
  solve();
}
