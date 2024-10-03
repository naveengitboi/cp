#include <bits/stdc++.h>
using namespace std;

//question 1590 october 3rd

int minSubarray(vector<int>& nums, int p){
    long long total = 0;
    for(auto num: nums){
        total+= num;
    }
    int rem = total%p;
    if(rem == 0) return 0;

    int minLen = nums.size();
    long long prefixSum = 0;
    unordered_map<int, int> mpp;
    mpp[0] = -1;
    for(int i = 0; i< nums.size(); i++){
        prefixSum += nums[i];
        int currentRem = prefixSum%p;
        //to avoid negative remainder we added p;
        int requiredRem = (currentRem - rem + p)%p;
        if(mpp.find(requiredRem) != mpp.end()){
            minLen = min(minLen, i - mpp[requiredRem]);
        }
        mpp[currentRem] = i;
    }

    if(minLen == nums.size()){
        minLen = -1;
    }

    return minLen;
}
