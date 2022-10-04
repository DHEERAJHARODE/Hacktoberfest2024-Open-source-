
//LOGIC: Explained in the code
//Time Complexity: O(N)


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    //Taking input the number of testcases
    ll t;
    cin>>t;
    //For each test case executing the code
    while(t--){
        //Taking input the size of vector and the sum
        ll size,sum;
        cin>>size>>sum;
        vector <ll> v;
        unordered_map<ll,ll>m;

        //Taking input the vector
        //Note: Unordered Map is taken input as the vector can have duplicate values as well.
        for(ll i=0;i<size;i++){
            ll temp=0;
            cin>>temp;
            v.push_back(temp);
        }
        vector <ll> ans;
        /**Checking if sum-(each of element of vector v) is present in the map if yes 
           then pushing the index of element for which the value is present 
           and the value corresponding to the key which is sum-the element in the answer vector, else pushing the 
           element and its index as key,value pair in unordered map**/
        for(ll i=0;i<size;i++){
            if(m.find(sum-v[i])!=m.end())
            {
                ans.push_back(i);
                ans.push_back(m[sum-v[i]]);
                break;
            }
            else
                m[v[i]]=i;
        }
        //Printing the required answer. 
        for(auto itr:ans){
            cout<<itr<<" ";
        }
        cout<<endl;
    }
    return 0;
}