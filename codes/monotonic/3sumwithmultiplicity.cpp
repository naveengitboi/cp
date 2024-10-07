//923 leetcode

#include <bits/stdc++.h>
using namespace std;


int threeSumMultiplicity(vector<int>& arr, int target){
    int mod = 10e9 + 7;
    int ans = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i< arr.size(); i++){
        ans = (ans + mp[target - arr[i]])%mod;
        for(int j = 0; j< i; j++){
            mp[arr[i] + arr[j]]++;
        }
    }
    return ans;
}
