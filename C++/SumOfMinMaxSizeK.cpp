#include <bits/stdc++.h>
using namespace std;

int sumOfMinMax(vector<int> arr, int k) {
    int tot = 0, n = arr.size();
    deque<int> dqmax;
    deque<int> dqmin;

    for(int i=0; i<n; i++) {
        if(!dqmax.empty() && dqmax.front() == i-k) dqmax.pop_front();
        if(!dqmin.empty() && dqmin.front() == i-k) dqmin.pop_front();

        while(!dqmax.empty() && arr[dqmax.back()] < arr[i]) dqmax.pop_back();
        while(!dqmin.empty() && arr[dqmin.back()] > arr[i])  dqmin.pop_back();

        dqmax.push_back(i);
        dqmin.push_back(i);

        if(i >= k-1) {
            // cout<<arr[dqmax.front()]<<" + "<<arr[dqmin.front()]<<" = "<<arr[dqmax.front()] + arr[dqmin.front()]<<endl;
            tot += arr[dqmax.front()] + arr[dqmin.front()];
        }
    }

    while(!dqmax.empty()) {
        cout<<dqmax.front()<<" ";
        dqmax.pop_front();
    }
    cout<<endl;
    while(!dqmin.empty()) {
        cout<<dqmin.front()<<" ";
        dqmin.pop_front();
    }

    return tot;
}

int main() {
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2, 3};
    int k = 4;

    cout<<sumOfMinMax(arr, k)<<endl;
    return 0;
}