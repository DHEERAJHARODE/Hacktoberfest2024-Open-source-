// a map stores the values in key value pairs and orders them according to keys(alphabetically for example)
// a unordered map stores values but are not ordered and keys are unique here
// a multipmap is ordered and storing multiple duplicate keys is possible
#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> mpp;
    mpp["arun"] = 17;
    mpp["sam"] = 25;
    mpp["gilly"] = 21;
    mpp["jon"] = 1;
    mpp["gilly"] = 21; 

    cout << "size: " << mpp.size() << endl; // 4
    cout << "Map is empty: " << mpp.empty() << endl;

    mpp.erase(mpp.find("sam"));
    for(auto it: mpp){
        cout << it.first << " " << it.second << endl;
    }

    // unordered map
    unordered_map<string, int> ump;
    //all functions more or less similar to map

    multimap<string,int> mmp;
    //all functions more or less similar to map
}