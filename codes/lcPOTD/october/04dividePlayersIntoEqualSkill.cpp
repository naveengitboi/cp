#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll dividePlayers(vector<int>& skill){
    ll total = 0;
    sort(skill.begin(), skill.end());
    int n = skill.size();
    ll mini = skill[0]+skill[1];
    ll maxi = skill[n-1]  + skill[n-2];

    ll avg = mini + (maxi - mini)/2;

    unordered_map<ll, ll>mpp;
    for(auto num: skill){
        mpp[num]++;
    }
    ll ans = 0;

    for(int i = 0; i< n; i++){
        int x = avg - skill[i];
        if(mpp.find(x) == mpp.end()){
            return -1;
        }
        ans += x*(skill[i]);
        mpp[x]--;
        mpp[skill[i]]--;
    }

    return ans;
}
