#include <bits/stdc++.h>

using namespace std;

//1497 question lc
bool canArrange(vector<int>& nums, int k){
    unordered_map<int, int> mpp;
    for(int i = 0; i< nums.size(); i++){
        int rem = nums[i]%k;
        if(rem < 0){
            rem += k;
        }
        mpp[rem%k]++;
    }

    int cnt  = 0;
    if(mpp[0]%2 != 0) return false;

    for(int i = 1; i<= k; i++){
        int xRem =i; 
        int requiredRem = k - xRem;
        if(mpp[xRem] != mpp[requiredRem]){
            return false;
        }
    }

    return true;
}
