#include <bits/stdc++.h>
using namespace std;



vector<int> solve(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<pair<int,int>> mp;
    for(int i = 0; i< n; i++){
        mp.push_back({nums[i], i});
    }
    sort(mp.begin(), mp.end());
    int i = 0;
   for(int j = 0; j< n; j++){
        auto p = mp[j];
        int idx = p.second;
        int val = p.first;
        if(j >0 ){
            if(mp[j].first == mp[j-1].first){
                ans[p.second] = i;
                continue;
            }
        }
        ans[p.second] = ++i;
    }


    return ans;
}


int main(){

    cout<<"working"<<endl;

    return 0;
}
