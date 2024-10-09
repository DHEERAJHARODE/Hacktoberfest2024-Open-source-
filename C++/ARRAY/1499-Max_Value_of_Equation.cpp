#include<bits/stdc++.h>
using namespace std;


int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>> pq;
    int ret = INT_MIN;
    for(auto point:points)
    {
        while(pq.size() && point[0]-pq.top().second>k)
            pq.pop();
        if(!pq.empty())
            ret = max(ret, point[0] + point[1] + pq.top().first);
        pq.push(make_pair(point[1]-point[0], point[0]));
    }
    return ret;
}

int main(){
    vector<vector<int>> points = {{1,3},{2,0},{5,10},{6,-10}};
    int k = 1;
    cout << findMaxValueOfEquation(points, k) << endl;
    return 0;
}