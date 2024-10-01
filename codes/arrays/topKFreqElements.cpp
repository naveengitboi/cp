#include <bits/stdc++.h>
using namespace std;


//using hmaps and priority queues

typedef pair<int, int> pii;

vector<int> topKfreq(vector<int>& nums, int k){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> ans;
    map<int, int> freq;
    int n = nums.size();
    for(int i = 0; i< n; i++){
        freq[nums[i]]++;
    }

    for(auto p: freq){
        pq.push({p.second, p.first});
        if(pq.size() > k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
