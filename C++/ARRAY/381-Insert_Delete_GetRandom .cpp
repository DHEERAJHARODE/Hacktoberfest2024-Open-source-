#include<bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> map; 
    
    RandomizedCollection() {}
    
    bool insert(int val) {
        arr.push_back(val);
        map[val].insert(arr.size()-1);
        return map[val].size() <= 1;
    }
    
    bool remove(int val) {
        if(map[val].size()==0) return false;
        int ind= *map[val].begin();
        map[val].erase(ind);
        
        int num= arr.back();
        swap(arr[ind], arr[arr.size()-1]);
        map[num].insert(ind);
        map[num].erase(arr.size()-1);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

int main(){
    vector<vector<int>> points = {{0,0},{3,0},{9,2}};
    int k = 3;
    RandomizedCollection randomizedCollection;
    for(auto &p : points){
        randomizedCollection.insert(p[0]);
        randomizedCollection.insert(p[1]);
    }
    vector<pair<int, int>> ans;
    for(int i=0; i<k; i++){
        ans.push_back({randomizedCollection.getRandom(), randomizedCollection.getRandom()});
        randomizedCollection.remove(ans[i].first);
        randomizedCollection.remove(ans[i].second);
    }
    for(auto &p : ans){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}